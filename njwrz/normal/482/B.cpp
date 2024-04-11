#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
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
int n;
class bit{
	public:
	int s[200005];
	void up(int p,int x){
		while(p<=n){
			s[p]+=x;
			p+=p&-p;
		}
	}
	int get(int p){
		int re=0;
		while(p){
			re=re+s[p];
			p-=p&-p;
		}
		RE re;
	}
	void clear(){
		FILL(s,0);
	}
}tree[30],t[30];
int l[100005],r[100005],x[100005];
int ans[100005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int k;
	cin>>n>>k;
	FOR(i,1,k){
		cin>>l[i]>>r[i]>>x[i];
		rep(j,0,30)if(x[i]&(1<<j)){
			tree[j].up(l[i],1);
			tree[j].up(r[i]+1,-1); 
		}
	}
	rep(i,0,30){
		FOR(j,1,n){
			if(tree[i].get(j))t[i].up(j,1);
		}
	}
	FOR(i,1,k){
		rep(j,0,30)if(!(x[i]&(1<<j))){
			if(t[j].get(r[i])-t[j].get(l[i]-1)==r[i]-l[i]+1){
				cout<<"NO";RE 0;
			}
		}
	}
	cout<<"YES\n";
	rep(i,0,30){
		FOR(j,1,n){
			if(t[i].get(j)-t[i].get(j-1))ans[j]+=(1<<i);
		}
	}
	FOR(i,1,n)cout<<ans[i]<<' ';
	RE 0;
}