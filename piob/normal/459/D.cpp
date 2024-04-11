#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define ALL(a) (a).begin(), (a).end()
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef pair<unsigned, unsigned> PUU;
typedef long long LL;
typedef long double K;

const int mod = 1000000007;

int n;
int R[1000010];
int D[1000010];
int T[1000010];
map<int, int> M;
LL res;

void add(int x, int y){
	while(x < n){
		D[x] += y;
		x += (x&-x);
	}
}

int get(int x){
	int r = 0;
	while(x){
		r += D[x];
		x -= (x&-x);
	}
	return r;
}

int main(){
	scanf("%d", &n);
	FWD(i,0,n)
		scanf("%d", &T[i]);
	BCK(i,n-1,-1){
		R[i] = ++M[T[i]];
		add(R[i], 1);
	}
	M.clear();
	FWD(i,0,n){
		add(R[i], -1);
		res += get(M[T[i]]++);
	}
	cout << res << endl;
	return 0;
}