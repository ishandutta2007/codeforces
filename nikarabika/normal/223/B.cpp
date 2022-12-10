#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pie;

#define PB push_back
#define MP make_pair
#define L first
#define R second

const int maxn = 2e5 + 85 - 69;
vector<int> v[28];
int dp[maxn], pd[maxn];
string s, t;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> s >> t;
	int match = -1;
	for(int i = 0; i < s.size(); i++){
		dp[i] = match;
		if(match + 1 < t.size() and s[i] == t[match + 1])
			match++;
	}
	match = t.size();
	pd[s.size()] = match;
	for(int i = s.size() - 1; i >= 0; i--){
		pd[i] = match;
		if(match - 1 >= 0 and s[i] == t[match - 1])
			match--;
	}
	for(int i = 0; i < t.size(); i++)
		v[t[i] - 'a'].PB(i);
	/*for(int i = 0; i < s.size(); i++)
		cout << dp[i] << ' ';
	cout << endl;
	for(int j = 0; j < s.size(); j++)
		cout << pd[j] << ' ';
	cout << endl;
	*/
	for(int i = 0; i < s.size(); i++){
		if(dp[i] + 1 < pd[i] - 1){
			cout << "NO" << endl;
			return 0;
		}
		int k = dp[i], l = pd[i];
		int id = lower_bound(v[s[i] - 'a'].begin(), v[s[i] - 'a'].end(), l - 1) - v[s[i] - 'a'].begin();
		if(id == v[s[i] - 'a'].size() or v[s[i] - 'a'][id] > k + 1){
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}