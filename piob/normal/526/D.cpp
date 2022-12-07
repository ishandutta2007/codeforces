#include <bits/stdc++.h>
#define REP(a,b) for(int a=0; a<(b); ++a)
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FWDS(a,b,c,d) for(int a=(b); a<(c); a+=d)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define ALL(a) (a).begin(), (a).end()
#define SIZE(a) ((int)(a).size())
#define VAR(x) #x ": " << x << " "
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll
#define gcd __gcd
#define x first
#define y second
#define st first
#define nd second
#define pb push_back

using namespace std;

template<typename T> ostream& operator<<(ostream &out, const vector<T> &v){ out << "{"; for(const T &a : v) out << a << ", "; out << "}"; return out; }
template<typename S, typename T> ostream& operator<<(ostream &out, const pair<S,T> &p){ out << "(" << p.st << ", " << p.nd << ")"; return out; }

typedef long long LL;
typedef pair<int, int> PII;
typedef long double K;
typedef vector<int> VI;

const int dx[] = {0,0,-1,1}; //1,1,-1,1};
const int dy[] = {-1,1,0,0}; //1,-1,1,-1};

void pref_suf(const char *w, int n, int *p) {
	p[0] = 0;
	for(int i=1;i<n;i++) {
	p[i] = p[i-1];
	while(p[i] > 0 && w[i] != w[p[i]]) p[i] = p[p[i]-1];
	if (w[i] == w[p[i]]) p[i]++;
	}
}

int n, k;
char buff[1000010];
int ps[1000010];

int main(){
	scanf("%d %d %s", &n, &k, buff);
	pref_suf(buff, n, ps);
	FWD(i,0,n){
		bool ok = 0;
		int len = i+1;
		int pie = (i+1-ps[i]);
		int r = len / pie;
		if(len % pie == 0){
			ok |= (r % k == 0);
			ok |= (r % (k+1) == 0);
		}
		if(r >= k){
			pie *= (r / k);
			r = len / pie;
			if(r == k) ok = 1;
			//if(ps[i]) good[i] |= good[ps[i]-1];
		}
		buff[i] = (ok ? '1' : '0');
	}
	printf("%s\n", buff);
	return 0;
}
/*
10 ababaababaab
15 ababaababaababaab
   ababa
        ababa
			 ababa
			 	  ababa
   ababaab
   	    	 	  
*/