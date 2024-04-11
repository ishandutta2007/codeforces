#include<bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
int l[500001];
int r[500001];
vector<pair<int,int> >v;
int n;
ll s;
bool ok(ll x){
	int cnt=0;
	ll cur=0ll;
	for (auto p:v){
		if (p.first<=x && p.second>=x && cnt<=(n/2)){
			cur+=x*1ll;
			cnt++;
		} else if (p.first>x){
			cur+=p.first;
			cnt++;
		}
		else cur+=p.first*1ll;
	}
	//cout<<x<<" "<<cur<<endl;
	return ((cnt>(n/2)) && cur<=s);
}
void solve(){
	cin>>n>>s;
	for (int i=1;i<=n;i++) cin>>l[i]>>r[i];
	v.clear();
	for (int i=1;i<=n;i++){
		v.push_back({l[i],r[i]});
	}
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	ll l=0ll;
	ll r=s;
	while (r-l>1){
		ll m=(l+r)/2;
		if (ok(m)) l=m;
		else r=m;
	}
	if (ok(r)) l=r;
	cout<<l<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
  	int tt;cin>>tt;
	while (tt--){
		solve();
	}
    return 0;
}