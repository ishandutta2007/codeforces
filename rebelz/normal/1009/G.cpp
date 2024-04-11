#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int inf=1<<30;
char s[100005],ans[100005];
int n,m,src,sink,tot=0;
int a[100005],num[100005][70],cnt[105];

int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++) ans[i]='~';
	for(int i=1;i<=n;i++) for(int j=0;j<(1<<6);j++) cnt[j]+=bool(j&(1<<(s[i]-'a')));
	m=readint();
	int x,y; char str[10];
	for(int i=1;i<=m;i++){
		x=readint(); scanf("%s",str+1); y=strlen(str+1);
		for(int j=1;j<=y;j++) a[x]^=1<<(str[j]-'a');
	}
	for(int i=1;i<=n;i++) if(!a[i]) a[i]=63;
	for(int i=n;i>=1;i--) for(int j=0;j<(1<<6);j++) num[i][j]=num[i+1][j]+bool(a[i]&j);
	for(int i=1;i<=n;i++){
		for(int j=0;j<=5;j++){
			if((a[i]&(1<<j))&&cnt[1<<j]){
				int tmp=1;
				for(int k=0;k<(1<<6);k++){
					if(num[i+1][k]<cnt[k]-((k>>j)&1)){
						tmp=0;
						break;
					}
				}
				if(tmp){
					ans[i]=j+'a';
					for(int k=0;k<(1<<6);k++) cnt[k]-=bool(k&(1<<j));
					break;
				}
			}
		}
		if(ans[i]=='~') return printf("Impossible\n"),0;
	}
	printf("%s",ans+1);
	return 0;
}