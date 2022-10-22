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
int a[200005];
int p[200005];
int n,m;
P<int,int> t[200005];
int len;
V<int> ans;
void solve(int x){
	ans.PB(x);
	int val=a[x]^a[x+1]^a[x+2];
	a[x]=a[x+1]=a[x+2]=val;
}
void print(){
	cout<<"YES\n";
	cout<<ans.size()<<'\n';
	if(ans.empty())RE;
	for(auto u:ans)cout<<u<<' ';
	cout<<'\n';
}
void solve(){
	cin>>n;
	ans.clear();m=len=0;
	FOR(i,1,n){
		cin>>a[i];
	}
	FOR(i,1,n)if(a[i])p[++m]=i;
	if((m&1)||n==m){
		cout<<"NO\n";RE ;
	}
	int l=1;
	p[m+1]=1e9;
	FOR(i,2,m+1){
		if(p[i]>p[i-1]+1){
			t[++len]=MP(p[l],p[i-1]);
			l=i;
		}
	}
	for(int i=1;i<=len;i++)if((t[i].S-t[i].F+1)&1){
		int pos=t[i].S;
		while(t[i+1].F-pos+1>3){
			solve(pos);
			pos+=2;
		}
		if(pos==t[i+1].F-1){
			t[i+1].F=t[i].F;continue;
		}
		while(pos>=t[i].F){
			solve(pos);
			pos-=2;
		}
		t[i+1].F++;
	}else{
		if(t[i].F!=1){
			for(int j=t[i].F;j<=t[i].S;j+=2){
				solve(j-1);
			}
		}else if(t[i].S!=n){
			for(int j=t[i].S;j>=t[i].F;j-=2){
				solve(j-1);
			}
		}
	}
	FOR(i,1,n)if(a[i]){
		cout<<"NO\n";RE ;
	}
	print();
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
	RE 0;
}