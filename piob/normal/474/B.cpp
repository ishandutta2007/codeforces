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

const int INF = 1000*1000*1000;

int dx[] = {0,0,-1,1}; //1,1,-1,1};
int dy[] = {-1,1,0,0}; //1,-1,1,-1};

const char* R = "qwertyuiopasdfghjkl;zxcvbnm,./";

int n, q;
int S[100010];

int main(){
	scanf("%d", &n);
	FWD(i,1,n+1){
		scanf("%d", &S[i]);
		S[i] += S[i-1];
	}
	scanf("%d", &q);
	FWD(i,0,q){
		int a;
		scanf("%d", &a);
		int lo = 0;
		int hi = n;
		while(hi-lo>1){
			if(S[(lo+hi)/2] < a)
				lo = (lo+hi)/2;
			else
				hi = (lo+hi)/2;
		}
		printf("%d\n", hi);
	}
	return 0;
}