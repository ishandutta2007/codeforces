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
char buff[3010];

int main(){
	scanf("%d", &n);
	scanf("%s", buff);
	int last = -1;
	int r = 0;
	FWD(i,0,n){
		if(buff[i] == 'L')
			if(last != -1)
				if((i-last-1)&1)
					++r;
		if(buff[i] == 'R')
			r += i-last-1;
		if(buff[i] != '.')
			last = i;
	}
	if(last == -1 || buff[last] == 'L')
		r += n-last-1;
	printf("%d\n", r);
	return 0;
}