#include<bits/stdc++.h>
using namespace std;
inline int readint(){
	int x=0;
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
const int maxn=5e3+5;
int n,x[maxn],y[maxn];
bool vis[maxn];
typedef long long ll;
inline ll sq(ll x){
	return x*x;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	for(int i=1;i<=n;i++){
		x[i]=readint();
		y[i]=readint();
	}
	int u=1;
	printf("1 ");
	vis[1]=1;
	for(int i=1;i<n;i++){
		int v=u;
		for(int j=1;j<=n;j++) if(!vis[j]&&sq(x[u]-x[j])+sq(y[u]-y[j])>sq(x[u]-x[v])+sq(y[u]-y[v])) v=j;
		printf("%d ",v);
		u=v;
		vis[u]=1;
	}
	return 0;
}