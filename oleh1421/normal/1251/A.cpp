#include<bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
void solve(){
	string s;cin>>s;
	int n=(int)s.size();
	set<char>st;
	int cnt=1;
	for (int i=1;i<n;i++){
		if (s[i]==s[i-1]) cnt++;
		else {
			if (cnt%2) st.insert(s[i-1]);
			cnt=1;
		}
	}
	if (cnt%2){
		st.insert(s[n-1]);
	}
	for (auto i:st) cout<<i;
	cout<<endl;
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