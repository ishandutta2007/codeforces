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

int n;

int A[N][3], S[N];

void solve(){
	scanf("%d", &n);
	for(int j = 0;j < 3;j++)
		for(int i = 0;i < n;i++)
			scanf("%d", &A[i][j]);
	S[0] = A[0][0];
	for(int i = 1;i + 1 < n;i++){
		if(A[i][0] == S[i - 1])
			S[i] = A[i][1];
		else
			S[i] = A[i][0];
	}
	S[n - 1] = A[n - 1][0];
	if(S[n - 1] == S[0] || S[n - 1] == S[n - 2])
		S[n - 1] = A[n - 1][1];
	if(S[n - 1] == S[0] || S[n - 1] == S[n - 2])
		S[n - 1] = A[n - 1][2];
	for(int i = 0;i < n;i++)
		printf("%d ", S[i]);
	printf("\n");
}

int main(){
	int T; scanf("%d", &T);
	for(;T--;) solve();
	return 0;
}