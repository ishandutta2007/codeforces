#include<bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
void solve(){
	string s;cin>>s;
	vector<int>v1;
	vector<int>v2;
	for (auto i:s){
		int cur=(i-'0');
		if (cur%2) v1.push_back(cur);
		else v2.push_back(cur);
	}
	reverse(v1.begin(),v1.end());
	reverse(v2.begin(),v2.end());
	while ((!v1.empty()) || (!v2.empty())){
		if (v2.empty() || (!v1.empty() && v1.back() < v2.back())){
			cout<<v1.back();
			v1.pop_back();
		} else {
			cout<<v2.back();
			v2.pop_back();
		}
	}
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