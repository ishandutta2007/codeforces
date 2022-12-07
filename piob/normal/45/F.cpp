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
typedef tuple<int, int, int> TI;

const int dx[] = {0,0,-1,1}; //1,1,-1,1};
const int dy[] = {-1,1,0,0}; //1,-1,1,-1};

const int INF = 1000000010;

int osobno(int c, int n){
	if(c <= n) return INF;
	return 3;
}

int heura2(int c, int n){
	if(n <= c-1){
		return 3;
	}
	int res = INF;
	int kursy = 4;
	n -= c-2;
	res = min(res, kursy + osobno(c, n));
	for(;;){
		if(2*n <= c){
			res = min(res, kursy + 1);
			break;
		}
		n -= (c/2) - 1;
		kursy += 2;
		res = min(res, kursy + osobno(c, n));
	}
	return res;
}

int heura(int c, int n){
	assert(c > 3);
	int res = heura2(c, n);
	int kursy = 0;
	for(;;){
		if(2*n <= c){
			res = min(res, kursy + 1);
			break;
		}
		n -= (c/2) - 1;
		kursy += 2;
		res = min(res, kursy + osobno(c, n));
	}
	return res;
}

bool safe(int w, int g){
	return w <= g || g == 0;
}

int dist[2][1003][1003];

int solve(int c, int n){
	FWD(i,0,2)
		FWD(j,0,n+1)
			FWD(k,0,n+1)
				dist[i][j][k] = INF;
	dist[0][n][n] = 0;
	queue<TI> Q;
	Q.push(TI{0,n,n});
	while(!Q.empty()){
		int s, w, g;
		tie(s, w, g) = Q.front();
		Q.pop();
		int d= dist[s][w][g];
		FWD(a,0,min(w, c)+1)
			FWD(b,0,min(g, c-a)+1)
				if(a + b && safe(w-a, g-b) && safe(n-w+a, n-g+b) && safe(a, b))
					if(dist[1-s][n-w+a][n-g+b] == INF){
						dist[1-s][n-w+a][n-g+b] = d + 1;
						Q.push(TI{1-s, n-w+a, n-g+b});
					}
	}
	if(dist[1][n][n] == INF) dist[1][n][n] = -1;
	return dist[1][n][n];
}

int main(){
	//cout << heura(5, 7) << endl;
	//int z;
	//scanf("%d", &z);
	//while(z--){
		int n, c;
		scanf("%d %d", &n, &c);
		if(c < 4){
			if(n < 14)
				printf("%d\n", solve(c, n));
			else
				printf("-1\n");
		}else
			printf("%d\n", heura(c, n));
	//}
	return 0;
}