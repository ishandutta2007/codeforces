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

const int mod = 1000000007;

int n;
char buff[200010];
int cnt[27];

int main(){
	scanf("%s", buff);
	n = strlen(buff);
	FWD(i,0,n) ++cnt[buff[i]-'a'];
	FWD(i,0,26)
		if(cnt[i]&1)
			BCK(j,25,i)
				if(cnt[j]&1){
					++cnt[i];
					--cnt[j];
					break;
				}

	FWD(i,0,26)
		FWD(t,0,cnt[i]/2)
			printf("%c", 'a'+i);

	FWD(i,0,26)
		if(cnt[i]&1)
			printf("%c", 'a'+i);

	BCK(i,25,-1)
		FWD(t,0,cnt[i]/2)
			printf("%c", 'a'+i);

	printf("\n");
	return 0;
}