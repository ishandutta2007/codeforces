#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;
typedef long double K;

const K PI = acos((long double)-1);

int n, k;
LL r;
map<int, int> C;
int T[400010];

int main(){
	scanf("%d %d", &n, &k);
	FWD(i,0,n) scanf("%d", &T[i]);
	int a=0, b=0;
	while(a < n){
		while(b < n && (!b || C[T[b-1]] != k))
			++C[T[b++]];
		if(C[T[b-1]] == k)
			r += n-b+1;
		--C[T[a++]];
	}
	cout << r << endl;
	return 0;
}