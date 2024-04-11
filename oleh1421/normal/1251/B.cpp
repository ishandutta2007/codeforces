#include<bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
void solve(){
	int n;cin>>n;
	vector<string>s(n);
	for (int i=1;i<=n;++i) cin>>s[i-1];
	int cnt0=0;
	int cnt1=0;
	int cnt=0;
	
	for (int i=0;i<n;i++){
		if ((int)s[i].size()%2==0) cnt++;
		for (auto j:s[i]){
			cnt0+=(j=='0');
			cnt1+=(j=='1');
		}
	}
	if ((cnt0%2 || cnt1%2) && cnt==n) cout<<n-1<<endl;
	else cout<<n<<endl;

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