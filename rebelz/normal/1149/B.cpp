#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,q,n1,n2,n3;
int now[30],lst[100005][30],d[255][255][255];
char s[100005],s1[255],s2[255],s3[255];

int main(){
	n=readint(); q=readint();
	scanf("%s",s+1);
	for(int i=1;i<=26;i++) now[i]=lst[n+1][i]=lst[n+2][i]=n+1;
	for(int i=n;i>=0;i--){
		for(int j=1;j<=26;j++) lst[i][j]=now[j];
		if(i>0) now[s[i]-'a'+1]=i;
	}
	for(int i=0;i<=250;i++) for(int j=0;j<=250;j++) for(int k=0;k<=250;k++) d[i][j][k]=n+1;
	d[0][0][0]=0;
	char opt,y; int x;
	while(q--){
		cin>>opt>>x;
		if(opt=='+'){
			cin>>y;
			if(x==1){
				s1[++n1]=y;
				for(int i=0;i<=n2;i++){
					for(int j=0;j<=n3;j++){
						d[n1][i][j]=lst[d[n1-1][i][j]][y-'a'+1];
						if(i>0) d[n1][i][j]=min(d[n1][i][j],lst[d[n1][i-1][j]][s2[i]-'a'+1]);
						if(j>0) d[n1][i][j]=min(d[n1][i][j],lst[d[n1][i][j-1]][s3[j]-'a'+1]);
					}
				}
				if(d[n1][n2][n3]==n+1) puts("NO");
				else puts("YES");
			}
			if(x==2){
				s2[++n2]=y;
				for(int i=0;i<=n1;i++){
					for(int j=0;j<=n3;j++){
						d[i][n2][j]=lst[d[i][n2-1][j]][y-'a'+1];
						if(i>0) d[i][n2][j]=min(d[i][n2][j],lst[d[i-1][n2][j]][s1[i]-'a'+1]);
						if(j>0) d[i][n2][j]=min(d[i][n2][j],lst[d[i][n2][j-1]][s3[j]-'a'+1]);
					}
				}
				if(d[n1][n2][n3]==n+1) puts("NO");
				else puts("YES");
			}
			if(x==3){
				s3[++n3]=y;
				for(int i=0;i<=n1;i++){
					for(int j=0;j<=n2;j++){
						d[i][j][n3]=lst[d[i][j][n3-1]][y-'a'+1];
						if(i>0) d[i][j][n3]=min(d[i][j][n3],lst[d[i-1][j][n3]][s1[i]-'a'+1]);
						if(j>0) d[i][j][n3]=min(d[i][j][n3],lst[d[i][j-1][n3]][s2[j]-'a'+1]);
					}
				}
				if(d[n1][n2][n3]==n+1) puts("NO");
				else puts("YES");
			}
		}
		else{
			if(x==1){
				for(int i=0;i<=n2;i++) for(int j=0;j<=n3;j++) d[n1][i][j]=n+1;
				n1--;
			}
			else if(x==2){
				for(int i=0;i<=n1;i++) for(int j=0;j<=n3;j++) d[i][n2][j]=n+1;
				n2--;
			}
			else if(x==3){
				for(int i=0;i<=n1;i++) for(int j=0;j<=n2;j++) d[i][j][n3]=n+1;
				n3--;
			}
			if(d[n1][n2][n3]==n+1) puts("NO");
			else puts("YES");
		}
	}
	return 0;
}