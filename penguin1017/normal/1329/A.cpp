#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define lb(x) ((x)&(-x))
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define de(x) cout<<x<<" x"<<endl
#define LCAFA rep(i,1,20)rep(j,1,n+1)fa[j][i]=fa[fa[j][i-1]][i-1]
#define all(x) x.begin(),x.end()
#define ls(x) x<<1
#define rs(x) x<<1|1
using namespace std;
const int N=1e5+9;
const ll mod=998244353;
int a[N],ans[N];
pii p[N];
int main(){
	int n,m;
	ll tot=0;
	scanf("%d%d",&n,&m);
	rep(i,0,m)scanf("%d",&a[i]),tot+=a[i];
	if(tot<n||m>n){
		cout<<-1;
		return 0;
	}
	int pos=0;
	rep(i,0,m){
		if(pos+a[i]>n){
			cout<<-1;
			return 0;
		}
		ans[i]=++pos;
		tot-=a[i];
		if(pos+tot>=n)continue;
		else pos=n-tot;
	}
	rep(i,0,m)printf("%d ",ans[i]);
}