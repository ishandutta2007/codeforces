#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

#define X first
#define Y second
#define PB push_back

/**

Jesam li sto rekao?
Sve sto sam rekao,
zaglusio je tutanj tramvaja...

Antun Soljan

**/

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;
typedef vector < int > vi;
typedef long long ll;

const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 20;
const int OFF = (1 << 18);

int n, m, d;
vector < ll > v;
ll pref[N];

int main(){
	scanf("%d%d%d", &n, &d, &m);
	for(int i = 0;i < n;i++){
		int x; scanf("%d", &x);
		v.PB(x);
	}
	sort(v.rbegin(), v.rend());
	int j = 0;
	while(j < n && v[j] > m) j++;
	int mks = n - j;
	for(int i = j;i < n;i++){
		pref[i - j + 1] = pref[i - j] + v[i];
	}
	ll ans = 0, sol = pref[mks]; 
	int cur = 0;
	for(int i = 0;i < n;i += d + 1){
		if(v[cur] <= m) break;
		ans += v[cur]; 
		sol = max(sol, ans + pref[min(n - cur * (d + 1) - 1, mks)]);
		cur++;
	}
	printf("%lld\n", sol);
	return 0;
}