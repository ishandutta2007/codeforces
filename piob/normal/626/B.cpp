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
int r, g, b;
char buff[210];

bool vis[6][6][6];
queue<tuple<int, int, int>> Q;

int main(){
	scanf("%d", &n);
	scanf("%s", buff);
	FWD(i,0,n){
		if(buff[i] == 'R') ++r;
		if(buff[i] == 'G') ++g;
		if(buff[i] == 'B') ++b;
	}
	r = min(r, 4);
	g = min(g, 4);
	b = min(b, 4);
	Q.push(tuple<int, int, int>(r, g, b));

	while(!Q.empty()){
		tie(r, g, b) = Q.front();
		Q.pop();
		if(vis[r][g][b]) continue;
		vis[r][g][b] = 1;

		if(r > 1) Q.push(tuple<int, int, int>(r-1, g, b));
		if(g > 1) Q.push(tuple<int, int, int>(r, g-1, b));
		if(b > 1) Q.push(tuple<int, int, int>(r, g, b-1));

		if(r && g) Q.push(tuple<int, int, int>(r-1, g-1, b+1));
		if(r && b) Q.push(tuple<int, int, int>(r-1, g+1, b-1));
		if(g && b) Q.push(tuple<int, int, int>(r+1, g-1, b-1));
	}

	if(vis[0][0][1]) printf("B");
	if(vis[0][1][0]) printf("G");
	if(vis[1][0][0]) printf("R");
	printf("\n");
	return 0;
}