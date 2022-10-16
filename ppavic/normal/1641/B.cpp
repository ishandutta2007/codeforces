#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;
typedef vector < int > vi;

const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7; // 998244353
const int LOG = 20;
const int OFF = (1 << 20);

int cnt[N], A[N], n;
vector < int > sz, v;

void solve(){
	scanf("%d", &n); sz.clear();
	for(int i = 0;i < n;i++)
		scanf("%d", A + i), sz.PB(A[i]), cnt[i] = 0;
	sort(sz.begin(), sz.end());
	for(int i = 0;i < n;i++){
		A[i] = lower_bound(sz.begin(), sz.end(), A[i]) - sz.begin();
		cnt[A[i]]++;
	}
	for(int i = 0;i < n;i++){
		if(cnt[i] & 1){
			printf("-1\n");
			return;
		}
	}
	for(int i = 0;i < n;i++) v.PB(A[i]);
 	int dos = 0;
	vector < int > fin;
	vector < pii > upd;
	for(;(int)v.size() > 0;){
//		printf("v : ");
//		for(int x : v) printf("%d ", x);
//		printf("\n");
		int j = 1;
		while(v[j] != v[0]) j++;
		if(j == 1){
			fin.PB(1); dos += 2;
			v.erase(v.begin()); v.erase(v.begin());
			continue;
		}
		for(int k = 1;k < j;k++)
			upd.PB({dos + j + k, v[k]});
	//		printf("%d %d\n", dos + j + k);
		fin.PB(j); dos += 2 * j;
		v.erase(v.begin()); v.erase(v.begin() + j - 1);
		reverse(v.begin(), v.begin() + j - 1);
	}	
	printf("%d\n", (int)upd.size());
	for(pii tmp : upd) printf("%d %d\n", tmp.X, sz[tmp.Y]);
	printf("%d\n", (int)fin.size());
	for(int x : fin) printf("%d ", 2 * x);
	printf("\n");
}

int main(){
	int T; scanf("%d", &T);
	for(;T--;) solve();
	return 0;
}