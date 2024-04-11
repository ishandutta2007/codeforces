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

int rev(int x){
	int y = 0;
	while(x){
		y = 10*y + x%10;
		x /= 10;
	}
	return y;
}

bool prime(int x){
	for(int i = 2; i*i <= x; ++i)
		if(x%i==0)
			return 0;
	return 1;
}

bool emirp(int x){
	return prime(x) && prime(rev(x)) && x != rev(x);
}

int main(){
	scanf("%d", &n);
	for(int i = 13; ; i+=2){
		if(emirp(i)){
			if(n==1){
				printf("%d\n", i);
				return 0;
			}else
				--n;
		}
	}
	return 0;
}