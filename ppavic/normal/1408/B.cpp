#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;
typedef pii pt;
typedef vector < int > vi;
typedef vector < ll > vl;

const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int LOG = 20;
const int OFF = (1 << LOG);

int A[N], n, k;

void solve(){
	scanf("%d%d", &n, &k);
	int raz = 0;
	for(int i = 0;i < n;i++){
		scanf("%d", A + i);
		raz += (!i || (A[i] != A[i - 1]));
	}
	if(k == 1){
		if(raz != 1)
			printf("-1\n");
		else
			printf("1\n");
		return;
	}
	int sol = 1;
	while(raz > k)
		raz -= k - 1, sol++;
	printf("%d\n", sol);
}	

int main(){
	int T;scanf("%d", &T);
	for(;T--;) solve();
	return 0;
}