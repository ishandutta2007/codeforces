#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

const long double PI = acos((long double)-1);

int n;
int R[110];
double a;

int main(){
	scanf("%d", &n);
	FWD(i,0,n) scanf("%d", &R[i]);
	sort(R, R+n);
	reverse(R, R+n);
	FWD(i,0,n){
		a += ((i&1)?-1:1) * R[i] * R[i];
	}
	cout << PI * a << endl;
}