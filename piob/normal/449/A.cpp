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
typedef pair<int, int> PII;
typedef vector<int> VI;

int dx[] = {0,0,-1,1}; //1,1,-1,1};
int dy[] = {-1,1,0,0}; //1,-1,1,-1};

int N, M, K;
LL n, m, k;
LL r;

int main(){
	scanf("%d %d %d", &N, &M, &K);
	n = N, m = M, k = K;
	if(n+m-2<k)
		printf("-1\n");
	else{
		FWD(z,0,2){
			for(LL d = 1; d*d <= n; ++d){
				if(k+2>d) r = max(r, (n/d)*(m/(k+2-d)));
				if(k+2>n/d) r = max(r, (n/(n/d))*(m/(k+2-n/d)));
			}
			swap(n, m);
		}
		cout << r << endl;
	}
}