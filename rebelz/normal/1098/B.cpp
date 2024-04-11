#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m,ans=1<<30;
char ch[4]={'A','T','G','C'};
int p[24][4]={0,1,2,3,0,1,3,2,0,2,1,3,0,2,3,1,0,3,1,2,0,3,2,1,1,0,2,3,1,0,3,2,1,2,0,3,1,2,3,0,1,3,0,2,1,3,2,0,2,0,1,3,2,0,3,1,2,1,0,3,2,1,3,0,2,3,0,1,2,3,1,0,3,0,1,2,3,0,2,1,3,1,0,2,3,1,2,0,3,2,0,1,3,2,1,0};
string a[300005];
int res[300005],tmp[300005];

int main(){
	n=readint(); m=readint();
	for(int i=1;i<=n;i++) cin>>a[i];
	int cho=0,lst=0;
	for(int g=0;g<24;g++){
		int now=0;
		for(int i=1;i<=n;i++){
			int x1=0,x2=0;
			for(int j=1;j<=m;j++){
				if(a[i][j-1]==ch[i&1?p[g][j&1?0:1]:p[g][j&1?2:3]]) x1++;
				if(a[i][j-1]==ch[i&1?p[g][j&1?1:0]:p[g][j&1?3:2]]) x2++;
			}
			if(x1>x2) tmp[i]=0,now+=m-x1;
			else tmp[i]=1,now+=m-x2;
		}
		if(now<ans) ans=now,cho=g,memcpy(res,tmp,sizeof(res));
	}
	for(int g=0;g<24;g++){
		int now=0;
		for(int i=1;i<=m;i++){
			int x1=0,x2=0;
			for(int j=1;j<=n;j++){
				if(a[j][i-1]==ch[i&1?p[g][j&1?0:1]:p[g][j&1?2:3]]) x1++;
				if(a[j][i-1]==ch[i&1?p[g][j&1?1:0]:p[g][j&1?3:2]]) x2++;
			}
			if(x1>x2) tmp[i]=0,now+=n-x1;
			else tmp[i]=1,now+=n-x2;
		}
		if(now<ans) ans=now,cho=g,memcpy(res,tmp,sizeof(res)),lst=1;
	}
	if(lst==0){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(res[i]==0) printf("%c",ch[i&1?p[cho][j&1?0:1]:p[cho][j&1?2:3]]);
				else printf("%c",ch[i&1?p[cho][j&1?1:0]:p[cho][j&1?3:2]]);
			}
			printf("\n");
		}
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(res[j]==0) printf("%c",ch[j&1?p[cho][i&1?0:1]:p[cho][i&1?2:3]]);
				else printf("%c",ch[j&1?p[cho][i&1?1:0]:p[cho][i&1?3:2]]);
			}
			printf("\n");
		}
	}
	return 0;
}