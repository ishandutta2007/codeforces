#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

const long double PI = acos((long double)-1);

int a, b, c, d;

int gcd(int a, int b){
	while(a&&b) a>b?a%=b:b%=a; return a+b;
}

int main(){
	scanf("%d %d %d %d", &a, &b, &c, &d);
	if(d*a < b*c){
		int g = gcd(b*c-d*a, b*c);
		printf("%d/%d\n", (b*c-d*a)/g, b*c/g);
	}else{
		int g = gcd(d*a-b*c, d*a);
		printf("%d/%d\n", (d*a-b*c)/g, d*a/g);
	}

}