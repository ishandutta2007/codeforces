#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
using LL=long long;
const int N=200005,K=20;
int T,n,w;
LL s[N],f[N][K],g[N][K];
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&w);
		rep(i,1,n){
			scanf("%lld",&s[i]);
			f[i][0]=s[i];
			g[i][0]=min(s[i],0LL);
		}
		rep(j,1,K-1){
			rep(i,1,n-(1<<j)+1){
				f[i][j]=f[i][j-1]+f[i+(1<<(j-1))][j-1];
				g[i][j]=min(g[i][j-1],g[i+(1<<(j-1))][j-1]+f[i][j-1]);
			}
		}
		int lb=-1,rb=-1;
		rep(i,1,n){
			int x=i;
			LL ss=w;
			per(j,K-1,0)if(x+(1<<j)-1<=n&&g[x][j]+ss>=0){
				ss+=f[x][j];
				x+=1<<j;
			}
			if(s[i]+w>=0){
				if(x-i>=rb-lb){
					lb=i,rb=x;
				}
			}
		}
		if(lb==-1)puts("-1");else printf("%d %d\n",lb,rb-1);
	}
	return 0;
}