//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
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

const int maxn = 1000;
string s[maxn];
int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) cin >> s[i];
	if(n == 1){
		cout << 6 << endl;
		return 0;
	}
	int Min = 1000;
	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++){
			int dif = 0;
			for(int k = 0; k < 6; k++) dif += s[i][k] != s[j][k];
			smin(Min, dif);
		}
	cout << (Min - 1) / 2;
	return 0;
}