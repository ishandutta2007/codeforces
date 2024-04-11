#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
int fa[200005];
int get(int x){
	RE fa[x]==x?x:fa[x]=get(fa[x]);
}
void merge(int x,int y){
	x=get(x);y=get(y);
	if(x!=y)fa[x]=y;
}
int n,m;
int a[100005],b[100005];
struct node{
	int x,y ,co;
};
bool cmp(node x,node y){
	RE x.co>y.co;
}
signed main(){
	V<node> v;
	cin>>n>>m;
	FOR(i,1,n)cin>>a[i];
	FOR(i,1,m)cin>>b[i];
	int sum=0;
	FOR(i,1,n){
		int l,x;
		cin>>l;
		FOR(j,1,l){
			cin>>x;
			v.PB((node){
				i,n+x,a[i]+b[x]
			});
			sum+=a[i]+b[x];
		}
	}
	sort(ALL(v),cmp);
	FOR(i,1,n+m)fa[i]=i;
	for(auto u:v){
		if(get(u.x)!=get(u.y)){
			merge(u.x,u.y);
			sum-=u.co;
		}
	}
	cout<<sum;
	RE 0;
}