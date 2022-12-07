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

int n;
char board[53][53];
char result[103][103];

void umark(int dx, int dy){
	result[n-1+dx][n-1+dy] = '.';
}

bool possible(int dx, int dy){
	return result[n-1+dx][n-1+dy] == 'x';
}

int main(){
	scanf("%d", &n);
	FWD(i,0,n) scanf("%s", board[i]);
	FWD(i,0,2*n-1) FWD(j,0,2*n-1) result[i][j] = 'x';

	result[n-1][n-1] = 'o';
	FWD(i,0,n)
		FWD(j,0,n)
			if(board[i][j] == 'o')
				FWD(di,-i,n-i)
					FWD(dj,-j,n-j)
						if(board[i+di][j+dj] == '.')
							umark(di, dj);
	FWD(i,0,n)
		FWD(j,0,n)
			if(board[i][j] == 'o')
				FWD(di,-i,n-i)
					FWD(dj,-j,n-j)
						if(possible(di, dj) && board[i+di][j+dj] == 'x')
							board[i+di][j+dj] = '.';
	bool works = 1;
	FWD(i,0,n)
		FWD(j,0,n)
			if(board[i][j] == 'x')
				works = 0;
	if(works){
		printf("YES\n");
		FWD(i,0,2*n-1){
			FWD(j,0,2*n-1)
				printf("%c", result[i][j]);
			printf("\n");
		}
	}else
		printf("NO\n");
	return 0;
}