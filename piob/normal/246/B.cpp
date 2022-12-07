#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int n, s;

int main(){
	scanf("%d", &n);
	FWD(i,0,n){
		int a;
		scanf("%d", &a);
		s += a;
	}
	printf("%d\n", n-(s%n?1:0));
	return 0;
}