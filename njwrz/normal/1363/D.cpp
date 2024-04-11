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
int a[1005],ans[1005];
V<int> v[1005];
bool f[1005];
void solve(){
	int k;
	cin>>n>>k;
	int len,x;
	FILL(a,0);
	FOR(i,1,k){
		cin>>len;v[i].clear();
		FOR(j,1,len){
			cin>>x;v[i].PB(x);
			a[x]=i;
		}
	}
	cout<<"? "<<n;
	FOR(i,1,n)cout<<' '<<i;cout<<'\n';cout.flush();
	int maxi;
	cin>>maxi;
	FOR(i,1,k)ans[i]=maxi;
	int l=1,r=n,mid;
	while(r>l){
		mid=(l+r)>>1;
		cout<<"? "<<mid-l+1;
		FOR(i,l,mid)cout<<' '<<i;cout<<'\n';cout.flush();
		int t;
		cin>>t;
		if(t!=maxi){
			l=mid+1;
		}else r=mid;
	}
	int p=a[l];
	FILL(f,0);
	for(auto u:v[p])f[u]=1;
	cout<<"? "<<n-v[p].size();
	FOR(i,1,n){
		if(!f[i]){
			cout<<' '<<i;
		}
	}
	cout<<'\n';
	int tt;
	cin>>tt;
	ans[p]=tt;
	cout<<"!";
	FOR(i,1,k)cout<<' '<<ans[i];cout<<'\n';cout.flush();
	string rr;
	cin>>rr;
}
int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}