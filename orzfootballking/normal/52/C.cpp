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
class segtree{
	public:
	int N=262144,inf=1e17;
	int add[524288],now[524288],l[524288],r[524288];
	void build(){
		rep(i,0,N)l[i+N]=r[i+N]=i+1;
		for(int i=N-1;i>=1;i--)l[i]=l[i<<1],r[i]=r[(i<<1)|1];
	}
	void push(int p){
		if(add[p]){
			add[p<<1]+=add[p];now[p<<1]+=add[p];
			add[(p<<1)|1]+=add[p];now[(p<<1)|1]+=add[p];
			add[p]=0;
		}
	}
	void up(int p,int l1,int r1,int x){
		if(l[p]>=l1&&r1>=r[p]){
			now[p]+=x;
			add[p]+=x;
			RE;
		}
		if(l1>r[p]||l[p]>r1)RE;
		push(p);
		up(p<<1,l1,r1,x);
		up((p<<1)|1,l1,r1,x);
		now[p]=min(now[p<<1],now[(p<<1)|1]);
	}
	int get(int p,int l1,int r1){
		if(l[p]>=l1&&r1>=r[p])RE now[p];
		if(l1>r[p]||l[p]>r1)RE inf;
		push(p);
		RE min(get(p<<1,l1,r1),get((p<<1)|1,l1,r1));
	}
}tree;
int cc(string &s){
	stringstream ss;
	ss<<s;
	int num;
	ss>>num;
	RE num;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	tree.build(); 
	int n,x;
	cin>>n;
	FOR(i,1,n){
		cin>>x;
		tree.up(1,i,i,x);
	}
	int q;cin>>q;
	string s,t;cin.get();
	FOR(i,1,q){
		getline(cin,s);
		t="";s+=" ";
		V<int> v;
		rep(i,0,s.size()){
			if(s[i]==' '){
				if(!t.size())continue;
				v.PB(cc(t));
				t="";
			}else{
				t+=s[i];
			}
		}
		if(v.size()==2){
			v[0]++;v[1]++;
			if(v[0]>v[1]){
				cout<<min(tree.get(1,1,v[1]),tree.get(1,v[0],n));
			}else cout<<tree.get(1,v[0],v[1]);
			cout<<'\n';
		}else{
			v[0]++;v[1]++;
			if(v[0]>v[1]){
				tree.up(1,1,v[1],v[2]);
				tree.up(1,v[0],n,v[2]);
			}else tree.up(1,v[0],v[1],v[2]);
		}
	}
	RE 0;
}