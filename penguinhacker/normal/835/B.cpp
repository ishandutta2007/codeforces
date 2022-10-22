#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
 
int k;
vector<int> v;
string s;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	cin >> k >> s;
	for (char c : s)
	    v.push_back(c-'0'), k-=c-'0';
	sort(v.rbegin(), v.rend());
	int ans=0;
	while(k>0) {
    	k-=9-v.back();
    	v.pop_back();
    	++ans;
	}
	cout << ans;
	return 0;
}
 
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/