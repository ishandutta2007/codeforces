#include<bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
int l[500001];
int r[500001];
vector<pair<int,int> >v;
void solve(){
	int n;cin>>n;
	for (int i=1;i<=n;i++) cin>>l[i]>>r[i];
	v.clear();
	for (int i=1;i<=n;i++){
		v.push_back({l[i],r[i]});
	}
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	ll sum=0ll;
	int cnt=0;
	multiset<int>st;
	for (int i=0;i<n;i++){
		st.insert(v[i].second);
		//cout<<v[i].first<<" "<<n-i-1<<" "<<cnt<<endl;
		if (v[i].first>n-i-1+cnt){
			sum+=(*st.begin())*1ll;
			st.erase(st.begin());
			cnt++;
		}
	} 
	cout<<sum<<endl;
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