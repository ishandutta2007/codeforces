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

int gcd(int a, int b){
	while(a&&b) a>b?a%=b:b%=a;
	return a+b;
}

int n;
map<int, LL> res;
map<int, int> cnt;

int main(){
	scanf("%d", &n);
	FWD(i,0,n){
		int a;
		scanf("%d", &a);
		map<int, int> nxt;
		for(auto c : cnt)
			nxt[gcd(c.x, a)] += c.y;
		++nxt[a];
		cnt.clear();
		cnt.swap(nxt);
		for(auto c : cnt)
			res[c.x] += c.y;
	}
	scanf("%d", &n);
	FWD(i,0,n){
		int a;
		scanf("%d", &a);
		cout << res[a] << endl;
	}
	return 0;
}