#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define ALL(a) (a).begin(), (a).end()
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef pair<unsigned, unsigned> PUU;
typedef long long LL;
typedef long double K;
typedef tuple<int, int, int> III;

const int mod = 1000000007;
const int INF = 1000000000;

int n, k;

int main(){
	scanf("%d %d", &n, &k);
	FWD(i,0,n){
		int a, b;
		scanf("%d %d", &a, &b);
		if(a == k || a == 7-k || b == k || b == 7-k){
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}