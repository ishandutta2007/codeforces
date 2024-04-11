#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define ALL(a) (a).begin(), (a).end()
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;
typedef long double K;

const int mod = 1000000007;
const K eps = 1e-9;

int n, r;
int s;

int main(){
	scanf("%d", &n);
	s = -1;
	FWD(i,0,n){
		int a;
		scanf("%d", &a);
		if(a){
			if(s == -1 || s == i-1)
				++r;
			else
				r += 2;
			s = i;
		}
	}
	printf("%d\n", r);
	return 0;
}