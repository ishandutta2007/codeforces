#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int n, m;
set<int> A;

int main(){
	scanf("%d %d", &n, &m);
	FWD(i,0,n){
		int a;
		scanf("%d", &a);
		A.insert(a);
	}
	FWD(i,0,m){
		int b;
		scanf("%d", &b);
		if(A.upper_bound(b) != A.begin())
			A.erase(--A.upper_bound(b));
	}
	printf("%d\n", (int)A.size());
	return 0;
}