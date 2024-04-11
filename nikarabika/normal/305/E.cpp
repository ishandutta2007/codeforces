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

const int maxn = 5e3 + 10;
int gn[maxn],
	lu[maxn * 2];
string s;
bool can[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for(int i = 1; i < maxn; i++){
		for(int j = 2; j < i; j++){
			int le = max(0, j - 1),
				ri = max(0, i - j);
			lu[gn[le] ^ gn[ri]] = i;
		}
		for(int j = 0; j <= i; j++)
			if(lu[j]^i){
				gn[i] = j;
				break;
			}
	}
	cin >> s;
	for(int i = 1; i + 1 < sz(s); i++)
		can[i] = s[i - 1] == s[i + 1];
	int xorall = 0,
		cnt = 0;
	vector<pii> vec;
	for(int i = 0; i < sz(s); i++){
		if(can[i]) cnt++;
		else if(cnt){
			vec.PB(MP(i - cnt - 1, cnt+2));
			xorall ^= gn[cnt+2];
			cnt = 0;
		}
	}
	if(!xorall){
		cout << "Second" << endl;
		return 0;
	}
	cout << "First\n";
	for(auto P : vec){
		int mx = P.R;
		for(int i = 2; i < mx; i++){
			int le = max(0, i - 1),
				ri = max(0, mx - i);
			if((gn[le] ^ gn[ri]) == (gn[mx] ^ xorall)){
				cout << P.L + i << '\n';
				return 0;
			}
		}
	}
	return 0;
}