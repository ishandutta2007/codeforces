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
typedef tuple<int, int, int> III;

const int mod = 1000000009;
const LL INF = 2000000000LL * 2000000000LL;

int n, m, k;
int T[100010];
map<int, int> M;
map<int, int> I;
vector<int> V;
vector<int> C[100010];

int main(){
	scanf("%d %d", &n, &m);
	FWD(i,0,n){
		scanf("%d", &T[i]);
		++M[T[i]];
	}
	for(auto p : M)
		if(p.y >= p.x){
			I[p.x] = V.size();
			V.push_back(p.x);
		}
	k = V.size();
	C[0].resize(k, 0);
	FWD(i,0,n){
		C[i+1] = C[i];
		if(I.find(T[i]) != I.end())
			++C[i+1][I[T[i]]];
	}
	FWD(i,0,m){
		int a, b, c = 0;
		scanf("%d %d", &a, &b);
		--a; --b;
		FWD(j,0,k){
			if(V[j] == C[b+1][j]-C[a][j])
				++c;
		}
		printf("%d\n", c);
	}
	return 0;
}