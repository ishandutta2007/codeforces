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

const int MAXN = 600010;

int n;
char word[MAXN];
int ps[MAXN];
int dp[MAXN];

void pref_suf(){
  ps[0] = 0;
  FWD(i,1,n){
    ps[i] = ps[i-1];
    while(ps[i] > 0 && word[i] != word[ps[i]]) ps[i] = ps[ps[i]-1];
    if (word[i] == word[ps[i]]) ps[i]++;
  }
}

vector<int> out;

void gen(int k){
	if(k){
		gen(ps[k-1]);
		out.push_back(k);
	}
}

int main(){
	//int z;
	//scanf("%d", &z);
	//while(z--){
		scanf("%s", word);
		n = strlen(word);
		pref_suf();
		BCK(i,n-1,-1){
			++dp[i];
			dp[ps[i]-1] += dp[i];
		}
		out.clear();
		gen(n);
		printf("%d\n", SIZE(out));
		for(int p : out){
			printf("%d %d\n", p, dp[p-1]);
		}
	//}
	return 0;
}