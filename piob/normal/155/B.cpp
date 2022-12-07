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

int n, k, r;
priority_queue<int> Q;

int main(){
	scanf("%d", &n);
	int k = 1;
	FWD(i,0,n){
		int a, b;
		scanf("%d %d", &a, &b);
		if(b){
			k += b-1;
			r += a;
		}else
			Q.push(a);
	}
	while(k && !Q.empty()){
		r += Q.top();
		Q.pop();
		--k;
	}
	printf("%d\n", r);
	return 0;
}