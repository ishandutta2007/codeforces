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

typedef PII point;
typedef PII dir;

int n, m, k;

map<point, int> id;
point P[500010];
dir nxt[500010][4];
long long res[500010];

vector<point> diag[2][200010];

void push(int x, int y, int i){
	point p(x, y);
	id[p] = i;
	P[i] = p;
	diag[0][x + y].push_back(p);
	diag[1][x - y + m].push_back(p);
}

long long dist(int a, int b){
	point p = P[a];
	point q = P[b];
	return abs(p.first - q.first) + abs(p.second - q.second);
}

/*
 0   1
  \ /
   x
  / \
 3   2
*/

int main(){
	scanf("%d %d %d", &n, &m, &k);
	++n;
	++m;
	FWD(i,0,k){
		int x, y;
		scanf("%d %d", &x, &y);
		push(x, y, i);
		res[i] = -1;
	}
	FWD(i,0,n){
		push(i, 0, k + i);
		push(i, m-1, k + n + i);

		nxt[k+i][0] = dir(k+i, 1);
		nxt[k+i][3] = dir(k+i, 2);

		nxt[k+n+i][1] = dir(k+n+i, 0);
		nxt[k+n+i][2] = dir(k+n+i, 3);
	}
	FWD(j,0,m){
		push(0, j, k + 2*n + j);
		push(n-1, j, k + 2*n + m + j);

		nxt[k+2*n+j][2] = dir(k+2*n+j, 1);
		nxt[k+2*n+j][3] = dir(k+2*n+j, 0);

		nxt[k+2*n+m+j][1] = dir(k+2*n+m+j, 2);
		nxt[k+2*n+m+j][0] = dir(k+2*n+m+j, 3);
	}
	FWD(d,0,n+m+1){
		sort(ALL(diag[0][d]));
		FWD(i,0,SIZE(diag[0][d])-1){
			int p = id[diag[0][d][i]];
			int q = id[diag[0][d][i+1]];
			nxt[p][0] = dir(q, 0);
			nxt[q][2] = dir(p, 2);
		}
	}
	FWD(d,0,n+m+1){
		sort(ALL(diag[1][d]));
		FWD(i,0,SIZE(diag[1][d])-1){
			int p = id[diag[1][d][i]];
			int q = id[diag[1][d][i+1]];
			nxt[p][1] = dir(q, 1);
			nxt[q][3] = dir(p, 3);
		}
	}
	int corners[] = {id[point(0,0)], id[point(0,m-1)], id[point(n-1,0)], id[point(n-1,m-1)]};
	dir s = dir(id[point(0,0)], 1);
	long long t = 0;
	do{
		dir sp = nxt[s.first][s.second];
		t += dist(s.first, sp.first) / 2;
		s = nxt[s.first][s.second];
		if(res[s.first] == -1)
			res[s.first] = t;
	}while(find(corners, corners+4, s.first) == corners+4);
	FWD(i,0,k) printf("%lld\n", res[i]);
	return 0;
}