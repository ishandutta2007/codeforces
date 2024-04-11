#include <bits/stdc++.h>
#define REP(a,b) for(int a=0; a<(b); ++a)
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FWDS(a,b,c,d) for(int a=(b); a<(c); a+=d)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second
#define pb push_back
#define re real()
#define im imag()

using namespace std;

typedef long long LL;
typedef pair<LL, LL> PII;
typedef double K;
typedef vector<int> VI;

int n;
int c[256];
char buff[110];

void read(int d){
	scanf("%s", buff);
	n = strlen(buff);
	FWD(i,0,n) c[buff[i]] += d;
}

int main(){
	read(1);
	read(1);
	read(-1);
	FWD(i,'A','Z'+1)
		if(c[i]){
			printf("NO\n");
			return 0;
		}
	printf("YES\n");
	return 0;
}