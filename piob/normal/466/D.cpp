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

const int mod = 1000000007;

int n, h;
map<int, LL> A, B;

int main(){
	scanf("%d %d", &n, &h);
	A[0] = 1;
	FWD(i,0,n){
		int a;
		scanf("%d", &a);
		for(auto p : A){
			//-
			if(a + p.x == h)
				B[p.x] += p.y;
			//[
			if(a + p.x+1 == h)
				B[p.x+1] += p.y;
			//]
			if(a + p.x == h && p.x)
				B[p.x-1] += p.x*p.y;
			//[]
			if(a + p.x+1 == h)
				B[p.x] += (p.x+1)*p.y;
		}
		A.clear();
		A.swap(B);
		for(auto &p : A) p.y %= mod;
	}
	printf("%d\n", (int)A[0]);
	return 0;
}