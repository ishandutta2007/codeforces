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

int n;
int p[110];
char vowels[] = {'a', 'e', 'i', 'o', 'u', 'y'};
char buff[110];

bool is_vowel(char c){
	return find(vowels, vowels+6, c) != vowels+6;
}

int main(){
	scanf("%d", &n);
	FWD(i,0,n) scanf("%d",&p[i]);
	FWD(i,0,n){
		scanf(" %[^\n]s", buff);
		if(p[i] != count_if(buff, buff+strlen(buff), is_vowel)){
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}