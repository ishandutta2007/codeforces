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
const int maxn=3e3+5;
int n,a[maxn];
int lst[maxn],nxt[maxn],f[maxn][maxn];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int T=readint();
	while(T--){
		n=readint();
		for(int i=1;i<=n;i++) a[i]=readint();
		for(int i=1;i<=n;i++) lst[i]=n+1;
		for(int i=n;i>0;i--){
			nxt[i]=lst[a[i]];
			lst[a[i]]=i;
		}
		for(int i=n;i>0;i--) for(int j=i;j<=n;j++){
			f[i][j]=f[i+1][j]+1;
			int u=nxt[i];
			while(u<=j){
				f[i][j]=min(f[i][j],f[i+1][u-1]+f[u][j]);
				u=nxt[u];
			}
		}
		printf("%d\n",f[1][n]-1);
	}
	#ifdef LOCAL
	fprintf(stderr,"%d\n",(int)clock());
	#endif
	return 0;
}