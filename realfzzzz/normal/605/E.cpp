#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll readint(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-'){
		f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=1e3+5;
int n;
typedef long double ld;
ld p[maxn][maxn],f[maxn],g[maxn];
bool vis[maxn];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) p[i][j]=readint()/100.0;
	for(int i=1;i<n;i++) f[i]=g[i]=1;
	for(int i=1;i<=n;i++){
		int u=0;
		for(int j=1;j<=n;j++)
			if(!vis[j]&&(!u||f[j]/(1-g[j])<f[u]/(1-g[u]))) u=j;
		f[u]/=1-g[u];
		vis[u]=1;
		for(int j=1;j<=n;j++) if(!vis[j]){
			f[j]+=f[u]*g[j]*p[j][u];
			g[j]*=1-p[j][u];
		}
	}
	printf("%.15Lf\n",f[1]);
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}