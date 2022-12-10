//sobskdrbhvk
//remember the flying, the bird dies ):(
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

string p = "Bulbasaur";

int cnt[100],
	cnt2[100];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	int ans = 1e5;
	for(auto c : s)
		cnt[c <= 'Z' ? c - 'A' : c - 'a' + 26]++;
	for(auto c : p)
		cnt2[c <= 'Z' ? c - 'A' : c - 'a' + 26]++;
	for(int i = 0; i < 52; i++)if(cnt2[i])
		smin(ans, cnt[i] / cnt2[i]);
	cout << ans << endl;
	return 0;
}