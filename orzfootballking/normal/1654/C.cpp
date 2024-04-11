#include<bits/stdc++.h>
#define int long long
#define lb long double
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
#define lc (x<<1)
#define rc ((x<<1)^1)
#define y1 yyyy1111
using namespace std;
void solve(){
	int n,x;
	cin>>n;
	multiset<int> s;
	int sum=0;
	FOR(i,1,n){
		cin>>x;
		sum+=x;
		s.emplace(x);
	}
	priority_queue<int> q;
	q.emplace(sum);
	s.emplace(1e18);
	rep(i,1,n){
		int now=q.top();q.pop();
		int t1=now/2,t2=(now+1)/2;
		if(*s.lwb(t1)==t1){
			s.erase(s.lwb(t1));
		}else q.emplace(t1);
		if(*s.lwb(t2)==t2){
			s.erase(s.lwb(t2));
		}else q.emplace(t2);
	}
	if(s.size()==1||n==1){
		cout<<"YES\n";
	}else cout<<"NO\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
	RE 0;
}