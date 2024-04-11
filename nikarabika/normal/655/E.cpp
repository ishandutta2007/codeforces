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

const int maxn = 1000 * 1000 + 10,
	  maxk = 30;
const LL Mod = 1000LL * 1000 * 1000 + 7;
int lastused[maxk];
int tim;
LL a[maxk];
int n, k;

int olduse(void){
	return min_element(lastused, lastused + k) - lastused;
}

int update(LL S, int x){
	LL tmp = S;
	S = (S + S - a[x] + 1) % Mod;
	a[x] = (tmp + 1) % Mod;
	lastused[x] = ++tim;
	return S;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> n >> k;
	cin >> s;
	int m = sz(s);
	LL sum = 0;
	for(int i = 0; i < m; i++)
		sum = update(sum, s[i] - 'a');
	for(int i = 0; i < n; i++)
		sum = update(sum, olduse());
	sum++;
	cout << ((sum + Mod) % Mod) << '\n';
	return 0;
}