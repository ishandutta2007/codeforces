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
int n,a[105],f[1005],s[1005];
int maxi=1e11;
void solve(){
	int sum=0;
	cin>>n;
	FOR(i,1,n)cin>>a[i],sum+=a[i];
	int t=-1;
	FOR(i,1,200){
		if(f[i]>maxi)break;
		if(s[i]==sum){
			t=i;break;
		}
	}
	if(t==-1){
		cout<<"NO\n";RE;
	}
	priority_queue<P<int,int> > q;
	FOR(i,1,n)q.emplace(MP(a[i],i));
	int lst=-1;
	for(int i=t;i>=1;i--){
		P<int,int> t=q.top();q.pop();
		if(t.S==lst){
			if(q.empty()){
				cout<<"NO\n";RE;
			}
			P<int,int> t2=q.top();q.pop();
			if(t2.F<f[i]){
				cout<<"NO\n";RE;
			}
			t2.F-=f[i];
			q.emplace(t);
			q.emplace(t2);lst=t2.S;continue;
		}
		if(t.F<f[i]){
			cout<<"NO\n";RE;
		}
		t.F-=f[i];
		q.emplace(t);lst=t.S;
	}
	cout<<"YES\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	f[1]=1;f[2]=1;
	FOR(i,3,1000){
		f[i]=f[i-1]+f[i-2];
		if(f[i]>maxi)break;
	}
	FOR(i,1,1000)s[i]=s[i-1]+f[i];
	int T;
	cin>>T;
	while(T--)solve();
	RE 0;
}