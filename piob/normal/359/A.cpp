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

int n, m;

int main(){
	scanf("%d %d", &n, &m);
	bool c = 0;
	FWD(i,0,n) FWD(j,0,m){
		int a;
		scanf("%d", &a);
		if(a)
			if(i==0||i==n-1||j==0||j==m-1)
				c = 1;
	}
	printf("%d\n", c?2:4);
	return 0;
}