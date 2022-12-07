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

const int mod = 1000000007;
const int INF = 1000000000;

int n;
int T[100010];

int main(){
	scanf("%d", &n);
	FWD(i,0,n) scanf("%d", &T[i]);
	int a = 0, b = -1;
	FWD(i,1,n){
		if(b == -1 && T[i] < T[a])
			a = i;
		if(T[i] > T[a] && (b == -1 || T[i] > T[b]))
			b = i;
		if(b != -1 && T[i] < T[b]){
			printf("3\n%d %d %d\n", a+1, b+1, i+1);
			return 0;
		}
	}
	a = 0, b = -1;
	FWD(i,1,n){
		if(b == -1 && T[i] > T[a])
			a = i;
		if(T[i] < T[a] && (b == -1 || T[i] < T[b]))
			b = i;
		if(b != -1 && T[i] > T[b]){
			printf("3\n%d %d %d\n", a+1, b+1, i+1);
			return 0;
		}
	}
	printf("0\n");
	return 0;
}