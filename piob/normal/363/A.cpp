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

int n;

int main(){
	scanf("%d", &n);
	bool f = 1;
	while(n || f){
		f = 0;
		int d = n%10;
		n /= 10;
		printf(d>4?"-O":"O-");
		printf("|");
		d %= 5;
		FWD(i,0,d) printf("O");
		printf("-");
		FWD(i,0,4-d) printf("O");
		printf("\n");
	}	
	return 0;
}