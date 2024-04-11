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
#define lc (x<<1)
#define rc ((x<<1)^1)
#define y1 yyyy1111
using namespace std;
int n,a[500005],x;
int sum[500005],tl[500005];
void solve(){
	cin>>n;
	FOR(i,1,n)cin>>a[i];
	cin>>x;
	FOR(i,1,n)a[i]-=x;
	deque<int> q;
	int l=0;
	FOR(i,1,n){
		sum[i]=sum[i-1]+a[i];
		while(!q.empty()&&sum[q.front()]>sum[i]){
			l=q.front()+1;
			q.pop_front();
		}
		while(!q.empty()&&sum[q.back()]<=sum[i-1])q.pop_back();
		q.PB(i-1);
		tl[i]=l;
	}
	int cnt=0,lst=-1e9;
	FOR(i,1,n){
		if(tl[i]){
			if(lst<tl[i]){
				lst=i;cnt++;
			}
		}
	}
	cout<<n-cnt<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
	RE 0;
}