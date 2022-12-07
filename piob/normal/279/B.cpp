#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

const int MAXN = 100010;
const int MAXV = 2000010;

int n, t, r;
int A[100010];

int main(){
	scanf("%d %d", &n, &t);
	FWD(i,0,n){
		scanf("%d", &A[i]);
	}
	int j = 0;
	FWD(i,0,n){
		while(j < n && A[j] <= t){
			t -= A[j];
			++j;
		}
		r = max(r, j-i);
		t += A[i];
	}
	printf("%d\n", r);
	return 0;
}