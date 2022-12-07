#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;
typedef long double K;

int n;
int main(){
	int z; scanf("%d", &z); while(z--){
		scanf("%d", &n);
		printf("%d\n", max(0, n-2));
	}
	return 0;
}