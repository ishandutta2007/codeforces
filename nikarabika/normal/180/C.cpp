#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;
int alo, ahi;
int lo[maxn], hi[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	s.insert(s.begin(), '*');
	for(int i = 1; i < s.size(); i++){
		lo[i] = lo[i - 1] + (s[i] <= 'z' and s[i] >= 'a');
		hi[i] = hi[i - 1] + (s[i] <= 'Z' and s[i] >= 'A');
	}
	alo = lo[s.size() - 1];
	ahi = hi[s.size() - 1];
	int ans = 1e9;
	for(int i = 0; i < s.size(); i++)
		ans = min(ans, lo[i] + ahi - hi[i]);
	cout << ans << endl;
	return 0;
}