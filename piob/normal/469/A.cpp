#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define ALL(a) (a).begin(), (a).end()
#define st first
#define nd second

using namespace std;

typedef pair<int, int> PII;
typedef pair<unsigned, unsigned> PUU;
typedef long long LL;
typedef long double K;

const int mod = 1000000007;
const int INF = 1000000000;

int n;
bool ps[110];

int main(){
	scanf("%d", &n);
	FWD(r,0,2){
		int k;
		scanf("%d", &k);
		FWD(i,0,k){
			int a;
			scanf("%d", &a);
			ps[a] = 1;
		}
	}
	bool ok = 1;
	FWD(i,1,n+1) if(!ps[i]) ok = 0;
	if(ok)
		printf("I become the guy.\n");
	else
		printf("Oh, my keyboard!\n");
	return 0;
}