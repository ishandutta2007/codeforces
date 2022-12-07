#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define ALL(a) (a).begin(), (a).end()
#define st first
#define nd second

using namespace std;

typedef pair<int, int> PII;
typedef pair<unsigned, unsigned> PUU;
typedef long long LL;
typedef long double K;

const int mod = 1000000007;
const int INF = 1000000000;

int n, c;
LL s, t, p, r;
int T[500010];

int main(){
	scanf("%d", &n);
	FWD(i,0,n){
		scanf("%d", &T[i]);
		s += T[i];
	}
	BCK(i,n-1,0){
		t += T[i];
		if(3*t == s) ++c;
	}
	FWD(i,0,n-1){
		if(3*t == s) --c;
		t -= T[i+1];
		p += T[i];
		if(3*p == s) r += c;
	}
	cout << r << endl;
	return 0;
}