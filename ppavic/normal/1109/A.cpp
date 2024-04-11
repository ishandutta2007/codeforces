#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <map>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;
typedef vector < int > vi;
typedef vector < ll > vl;

const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int LOG = 20;
const int MOD = 1e9 + 7;
const int BASE = 31337;

map < int, int > mp[2];
int n, cur;

int main(){
	mp[1][cur]++;
	ll sol = 0;
	scanf("%d", &n);
	for(int i = 0;i < n;i++){
		int x;scanf("%d", &x);
		cur ^= x;
		sol += mp[i % 2][cur];
		mp[i % 2][cur]++;
		
	}
	printf("%lld\n", sol);
	return 0;
}