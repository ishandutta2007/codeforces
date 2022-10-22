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
int a[500005],sum[500005],n;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int mid;
	cin>>n;
	mid=(n/2)+(n&1);
	FOR(i,1,mid)cin>>a[i];
	int x;
	cin>>x; 
	FOR(i,mid+1,n)a[i]=x;
	FOR(i,1,n)sum[i]=sum[i-1]+a[i];
	int t=0;
	multiset<int> s;
	V<int> v;
	FOR(i,1,n-mid+1){
		int now=sum[i+mid-1]-sum[i-1];
		v.PB(now);s.emplace(now);
	}
	int len=v.size();
	FOR(i,1,len){
		int now=(*s.begin())+t;
		if(now>0){
			cout<<mid+i-1;RE 0;
		}
		t+=x;
		s.erase(s.lwb(v.back()));
		v.pop_back();
	}
	cout<<-1;
	RE 0;
}