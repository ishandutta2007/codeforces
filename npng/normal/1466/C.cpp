#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int Maxn=100000;
const int Inf=0x3f3f3f3f;
int n;
char s[Maxn+5];
int f[2][26][26];
int g[2][26][26];
void solve(){
	scanf("%s",s+1);
	n=0;
	while(s[++n]!='\0');
	n--;
	memset(f[0],0,sizeof f[0]);
	memset(g[0],0,sizeof g[0]);
	for(int i=1;i<=n;i++){
		int cur=(i&1),lst=cur^1;
		memset(f[cur],0x3f,sizeof f[cur]);
		memset(g[cur],0x3f,sizeof g[cur]);
		for(int j=0;j<26;j++){
			for(int k=0;k<26;k++){
				if(j==k){
					continue;
				}
				f[cur][j][k]=min(f[cur][j][k],g[lst][k][j]+(j!=s[i]-'a'));
			}
		}
		for(int j=0;j<26;j++){
			int minn_1=Inf,minn_2=Inf;
			for(int k=0;k<26;k++){
				if(f[cur][j][k]<minn_1){
					minn_2=minn_1;
					minn_1=f[cur][j][k];
				}
				else if(f[cur][j][k]<minn_2){
					minn_2=f[cur][j][k];
				}
			}
			for(int k=0;k<26;k++){
				g[cur][j][k]=(f[cur][j][k]==minn_1?minn_2:minn_1);
			}
		}
	}
	int ans=Inf;
	for(int i=0;i<26;i++){
		for(int j=0;j<26;j++){
			ans=min(ans,f[n&1][i][j]);
		}
	}
	printf("%d\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}