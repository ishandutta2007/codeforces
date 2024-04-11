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

int n, m, r;
vector<PII> H;

int det(PII a, PII b, PII c){
	return (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x);
}

int dist(PII a, PII b){
	return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

int w, c;
vector<PII> R, C;

void solve(int z=0, int k=0){
	if(k == n){
		if(c > w){
			w = c;
			R = C;
		}
	}else{
		FWD(i,z,m){
			int sc = c;
			for(PII p : C)
				c += dist(p, H[i]);
			C.push_back(H[i]);
			solve(i, k+1);
			C.pop_back();
			c = sc;
		}
	}
}

int main(){
	scanf("%d %d", &n, &r);
	if(n&1){
		FWD(y,0,r+1){
			int x = 0;
			while(x*x + y*y <= r*r) ++x;
			--x;
			while(H.size() > 1 && det(H[H.size()-2], H.back(), PII(x,y)) <= 0)
				H.pop_back();
			H.push_back(PII(x,y));
		}
		m = H.size();
		FWD(i,0,m){
			H.push_back(PII(-H[i].x, H[i].y));
			H.push_back(PII(H[i].x, -H[i].y));
			H.push_back(PII(-H[i].x, -H[i].y));
		}
		sort(H.begin(), H.end());
		H.erase(unique(H.begin(), H.end()), H.end());
		m = H.size();
		solve();
		printf("%d\n", w);
		FWD(i,0,n)
			printf("%d %d\n", R[i].x, R[i].y);
	}else{
		printf("%d\n", n*n*r*r);
		FWD(i,0,n/2) printf("0 %d\n", r);
		FWD(i,0,n/2) printf("0 %d\n", -r);
	}
	return 0;
}