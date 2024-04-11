#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;
typedef vector < int > vi;
typedef set < int > si;
typedef vector < ll > vl;
typedef pair < ll, ll > pll;

const int N = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int BS = 31337;

unordered_map < int, int > mp;

int n, a[N], ans;

int main(){
	scanf("%d", &n); ans = n;
	for(int i = 0;i < n;i++) scanf("%d", a + i);
	for(int i = 0;i < n;i++){
		int cnt = 0;
		for(int j = 0;j < n;j++)
			mp[a[j]]++, cnt += (mp[a[j]] == 1);
		if(cnt == n){
			ans = 0; break;
		}
		for(int j = i;j < n;j++){
			mp[a[j]]--; cnt -= (mp[a[j]] == 0);
			//printf("i = %d j = %d cnt = %d\n", i, j, cnt);
			if(cnt == n - (j - i + 1))
				ans = min(ans, j - i + 1);
		}
		mp.clear();
	}
	printf("%d\n", ans);
	return 0;
}