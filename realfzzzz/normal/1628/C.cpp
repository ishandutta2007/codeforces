#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=1e3+5;
int n,a[maxn][maxn];
bool c[maxn][maxn];
const int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
int ans;
void upd(int x,int y){
	ans^=a[x][y];
	for(int i=0;i<4;i++) c[x+dx[i]][y+dy[i]]^=1;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++) a[i][j]=read();
		ans=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++) c[i][j]=0;
		for(int i=2;i<=n;i++)
			for(int j=1;j<=n;j++) if(!c[i-1][j]) upd(i,j);
		printf("%d\n",ans);
	}
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}