//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

int cnt[26];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	for(auto c : s)
		cnt[c - 'A']++;
	sort(cnt, cnt + 26, greater<int>());
	if(cnt[0] == 1)
		cout << 30 << endl;
	else if(cnt[0] == 2){
		if(cnt[1] == 2){
			if(cnt[2] == 2)
				cout << 6 << endl;
			else
				cout << 8 << endl;
		}
		else
			cout << 15 << endl;
	}
	else if(cnt[0] == 3){
		if(cnt[1] == 3)
			cout << 1 + 1 << endl;
		else if(cnt[1] == 2)
			cout << 1 + 2 << endl;
		else
			cout << 2 + 3 << endl;
	}
	else if(cnt[0] == 4)
		cout << 2 << endl;
	else
		cout << 1 << endl;
	return 0;
}