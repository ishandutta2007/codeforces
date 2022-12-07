#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int n;
char S[1000010];
LL a, b, x;

int main(){
	scanf("%s", S);
	n = strlen(S);
	FWD(i,0,n){
		if(S[i] == '=')
			S[i] = '0';
		if(S[i] == '^')
			x = i;
		else{
			a += S[i] - '0';
			b -= i * (S[i] - '0');
		}
	}
	if(a*x + b > 0)
		printf("left\n");
	if(a*x + b == 0)
		printf("balance\n");
	if(a*x + b < 0)
		printf("right\n");
	return 0;
}