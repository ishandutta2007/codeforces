#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,ncnt;
int a[100005],g[100005],h[100005];
bool vis[100005];
vector<int> v[100005];

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=1;i<=n;i++) if(a[a[i]]!=a[i]) return printf("-1\n"),0;
	for(int i=1;i<=n;i++) v[a[i]].push_back(i);
	for(int i=1;i<=n;i++){
		if(vis[a[i]]) continue;
		vis[a[i]]=++ncnt;
		for(auto x:v[a[i]]) g[x]=ncnt;
		h[ncnt]=a[i];
	}
	printf("%d\n",ncnt);
	for(int i=1;i<=n;i++) printf("%d ",g[i]);
	printf("\n");
	for(int i=1;i<=ncnt;i++) printf("%d ",h[i]);
	printf("\n");
	return 0;
}