#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
#define N 45

LL n,m,ans,a[N],nxt[N],go[N][2],f1[N][N],f2[N][N];
vector<LL> g1[N],g2[N];
char s[N];

int main(){
	scanf("%lld%s",&m,s+1); n=strlen(s+1);
	for (LL i=1;i<=n;++i) a[i]=s[i]-'0';
	for (LL i=2,j=0;i<=n;++i){
		for (;j&&a[j+1]!=a[i];j=nxt[j]);
		nxt[i]=a[j+1]==a[i]?++j:j;
	}
	for (LL i=0;i<=n;++i){
		if (i<n) go[i][a[i+1]]=i+1;
		for (LL j:{0,1}){
			if (!go[i][j]){
				go[i][j]=go[nxt[i]][j];
			}
		}
	}
	for (LL i=0;i<=n;++i){
		for (LL j:{0,1}){
			g1[i].push_back(go[i][j]);
			g2[go[i][j]].push_back(i);
		}
	}
	f1[0][n]=f2[0][n]=1;
	for (LL i=1;i<=m;++i){
		for (LL j=0;j<=n;++j){
			for (LL k:g1[j]){
				if (k!=n) f1[i][k]+=f1[i-1][j];
			}
			for (LL k:g2[j]){
				f2[i][k]+=f2[i-1][j];
			}
		}
	}
	for (LL i=0;i<=n;++i){
		for (LL j=0;j<=m;++j){
			ans+=f1[j][i]*f2[m-j][i];
		}
	}
	printf("%lld\n",ans);
	
	return 0;
}