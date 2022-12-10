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

const int maxn = 250;
const LL Inf = 1000LL * 1000000 * 1000 * 1000000;
vector<pll> vec;
LL s[maxn],
   d[maxn],
   ans[maxn];
int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> s[i] >> d[i];
	vec.PB(MP(-1, 1));
	vec.PB(MP(Inf, Inf));
	for(int i = 0; i < n; i++){
		for(int j = 0; j + 1 < sz(vec); j++){
			if(vec[j].R <= s[i] and vec[j + 1].L >= s[i] and s[i] + d[i] <= vec[j + 1].L){
				vec.insert(vec.begin() + j + 1, MP(s[i], s[i] + d[i]));
				ans[i] = s[i];
				goto hell;
			}
		}
		for(int j = 0; j + 1 < sz(vec); j++)
			if(vec[j].R + d[i] <= vec[j + 1].L){
				LL st = vec[j].R;
				ans[i] = st;
				vec.insert(vec.begin() + j + 1, MP(st, st + d[i]));
				break;
			}
hell:;
	}
	for(int i = 0; i < n; i++)
		cout << ans[i] << ' ' << ans[i] + d[i] - 1 << endl;
	return 0;
}