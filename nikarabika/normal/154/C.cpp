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

const int maxn = 1000 * 1000 + 1;
const LL base = 2,
	  Mod = 1e13 + 7;
int n, m;
LL P[maxn],
   Hash[maxn];

int main(){
	P[0] = 1;
	for(int i = 1; i < maxn; i++)
		P[i] = (P[i - 1] * base) % Mod;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++){
		int fi, se;
		scanf("%d%d", &fi, &se), fi--, se--;
		Hash[fi] = (Hash[fi] + P[se]);
		Hash[se] = (Hash[se] + P[fi]);
	}
	vector<LL> vec;
	for(int i = 0; i < n; i++){
		Hash[i] %= Mod;
		vec.PB(Hash[i]);
		Hash[i] = (Hash[i] + P[i]) % Mod;
		vec.PB(Hash[i]);
	}
	sort(all(vec));
	LL ans = 0;
	LL cnt = 1;
	vec.PB(-1);
	for(int i = 1; i < sz(vec); i++){
		if(vec[i] == vec[i - 1])
			cnt++;
		else{
			ans += cnt * (cnt - 1) / 2;
			cnt = 1;
		}
	}
	printf("%I64d", ans);
	return 0;
}