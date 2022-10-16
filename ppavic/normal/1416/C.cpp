#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair < int, int > pii;
typedef vector < int > vi;

const int N = 3e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 31;
const int OFF = (1 << LOG);

ll kol[LOG][2];
vi st;
int n;

void rijesi(vi v, int dub){
	if(dub == -1 || (int)v.size() == 0)
		return;
	int dos[2] = {0, 0};
	vi nxt[2];
	for(int x : v){
		int ja = !!(x & (1 << dub));
		kol[dub][ja] += dos[!ja];		
		dos[ja]++;
		nxt[ja].PB(x);
	}
	rijesi(nxt[0], dub - 1);
	rijesi(nxt[1], dub - 1);
}

int main(){
	scanf("%d", &n);
	for(int i = 0;i < n;i++){
		int tmp; scanf("%d", &tmp);
		st.PB(tmp);
	}
	rijesi(st, 29);
	int ans = 0; ll uk = 0;
	for(int i = 0;i < 30;i++){
		if(kol[i][1] < kol[i][0]){
			ans += (1 << i);
			uk += kol[i][1];
		}
		else
			uk += kol[i][0];
	}
	printf("%lld %d\n", uk, ans);
	return 0;
}