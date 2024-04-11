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

struct minqueue {
	queue<int> data;
	deque<int> minq;
	void push(int a){
		data.push(a);
		while(!minq.empty() && minq.back() > a) minq.pop_back();
		minq.push_back(a);
	}
	void pop(){
		if(minq.front() == data.front())
			minq.pop_front();
		data.pop();
	}
	int getmin(){
		return minq.front();
	}
};

int n, m, k;
char buff[2010][2010];
PII place[2010];
int up[2010][2010], down[2010][2010];
int res[2010];
int dp[2010][2010];

bool check(int x, int y, int s){
	//printf("check %d %d %d\n", x, y, s);
	//FWD(i,0,n) printf("%s\n", buff[i]);
	minqueue Qup, Qdown;
	FWD(r,0,s+1)
		if(y && buff[x][y-1] != 'X')
			--y;
	FWD(i,0,s){
		if(y == m || buff[x][y] == 'X') return 0;
		Qup.push(up[x][y]);
		Qdown.push(down[x][y]);
		++y;
	}
	FWD(r,0,s+1){
		if(Qup.getmin() + Qdown.getmin() - 1 >= s) return 1;
		if(y == m || buff[x][y] == 'X') break;
		Qup.pop();
		Qup.push(up[x][y]);
		Qdown.pop();
		Qdown.push(down[x][y]);
		++y;
	}
	return 0;
}

int main(){
	scanf("%d %d %d", &n, &m, &k);
	FWD(i,0,n) scanf("%s", buff[i]);
	FWD(i,0,k){
		scanf("%d %d", &place[i].x, &place[i].y);
		--place[i].x; --place[i].y;
		buff[place[i].x][place[i].y] = 'X';
	}
	
	FWD(j,0,m)
		up[0][j] = (buff[0][j] == 'X' ? 0 : 1);
	FWD(i,1,n)
		FWD(j,0,m)
			up[i][j] = (buff[i][j] == 'X' ? 0 : up[i-1][j]+1);

	FWD(j,0,m)
		down[n-1][j] = (buff[n-1][j] == 'X' ? 0 : 1);
	BCK(i,n-2,-1)
		FWD(j,0,m)
			down[i][j] = (buff[i][j] == 'X' ? 0 : down[i+1][j]+1);

	int b = 0;
	FWD(i,0,n)
		FWD(j,0,m){
			if(buff[i][j] == 'X') continue;
			if(i == 0 || j == 0){
				dp[i][j] = 1;
			}else{
				dp[i][j] = min(dp[i-1][j], dp[i][j-1]);
				if(dp[i][j] <= min(i,j) && buff[i-dp[i][j]][j-dp[i][j]] != 'X')
					++dp[i][j];
			}
			b = max(b, dp[i][j]);
		}

	BCK(q,k-1,-1){
		res[q] = b;
		int x, y; tie(x, y) = place[q];
		buff[x][y] = '.';
		
		up[x][y] = (x == 0 ? 1 : up[x-1][y] + 1);
		FWD(xp,x+1,n) if(buff[xp][y] != 'X') up[xp][y] = up[xp-1][y] + 1;

		down[x][y] = (x == n-1 ? 1 : down[x+1][y] + 1);
		BCK(xp,x-1,-1) if(buff[xp][y] != 'X') down[xp][y] = down[xp+1][y] + 1;

		while(check(place[q].x, place[q].y, b+1)) ++b;
	}

	FWD(q,0,k) printf("%d\n", res[q]);
	return 0;
}