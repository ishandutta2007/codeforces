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
typedef double K;
typedef vector<int> VI;

int dx[] = {0,0,-1,1}; //1,1,-1,1};
int dy[] = {-1,1,0,0}; //1,-1,1,-1};

int n;
vector<int> D[100010];
vector<int> X[100010];
bool fr[100010];
vector<PII> R;

int main(){
	scanf("%d", &n);
	FWD(i,2,n+1){
		int x = i;
		for(int d = 2; d*d <= x; ++d){
			if(x%d==0){
				D[i].push_back(d);
				X[d].push_back(i);
				while(x%d==0)
					x /= d;
			}
		}
		if(x > 1){
			D[i].push_back(x);
			X[x].push_back(i);
		}
		fr[i] = 1;
	}
	BCK(d,n,1){
		FWD(i,0,(int)X[d].size())
			if(X[d][i]%2==0 && fr[X[d][i]])
				swap(X[d][i], X[d].back());
		int last = -1;
		FWD(i,0,(int)X[d].size()){
			if(!fr[X[d][i]]) continue;
			if(last == -1)
				last = X[d][i];
			else{
				fr[last] = 0;
				fr[X[d][i]] = 0;
				R.push_back(PII(last, X[d][i]));
				last = -1;
			}
		}
	}
	printf("%d\n", (int)R.size());
	for(PII p : R)
		printf("%d %d\n", p.x, p.y);
	return 0;
}