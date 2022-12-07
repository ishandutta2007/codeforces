#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int n, k, b;
int S[150010];

int main(){
	scanf("%d %d", &n, &k);
	FWD(i,0,n){
		int a;
		scanf("%d", &a);
		S[i+1] = S[i] + a;
	}
	FWD(i,1,n-k+1)
		if(S[b+k]-S[b] > S[i+k]-S[i])
			b = i;
	printf("%d\n", b+1);
	return 0;
}