#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
  
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define fi first
#define se second
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl
#define inf 0x3f3f3f3f

typedef unsigned long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef pair<long long,int> pli;
typedef double db;
// head

const int N=2e6+5;

struct bing {
	int fa[N];
	void init() {rep(i,1,N) fa[i]=i;}
	int find(int x) {return fa[x]==x?x:fa[x]=find(fa[x]);}
	void unite(int x,int y) {fa[find(x)]=find(y);}
	bool same(int x,int y) {return find(x)==find(y);}
}bi[2];

int n,m1,m2;

int main() {
	rep(i,0,2) bi[i].init();
	cin>>n>>m1>>m2;
	int op=m1>m2?0:1;
	rep(i,1,m1+1) {
		int u,v; 
		scanf("%d%d",&u,&v);
		bi[op].unite(u,v);
	}
	rep(i,1,m2+1) {
		int u,v; 
		scanf("%d%d",&u,&v);
		bi[1-op].unite(u,v);
	}
	printf("%d\n",min(n-1-m1,n-1-m2));
	rep(i,1,n+1) if (!bi[0].same(1,i)&&!bi[1].same(1,i)) {
		bi[0].unite(1,i),bi[1].unite(1,i);
		printf("%d %d\n",1,i);
	}
	for (int a=2,b=2;a<=n;a++) {
		if (bi[0].same(1,a)) continue;
		while (b<=n&&bi[1].same(1,b)) b++;
		if (b<=n) {
			bi[0].unite(a,b),bi[1].unite(a,b);
			printf("%d %d\n",a,b);	
		}
	}
	return 0;	
}