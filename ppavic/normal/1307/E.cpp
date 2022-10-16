#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <vector>
#include <map>
#include <algorithm>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;
typedef vector < int > vi;

const int N = 5005;
const int MOD = 1e9 + 7;

inline int add(int A,int B){
	if(A + B >= MOD) return A + B - MOD;
	return A + B;
}

inline int sub(int A,int B){
	if(A - B < 0) return A - B + MOD;
	return A - B;
}

inline int mul(int A,int B){
	return (ll)A * B % MOD;

}

pii dp[N][2][2][2]; // postigao granicu s lijeve, mogu s lijeve, mogu s desne
int m, n, L[N], R[N], gran;
vector < pii > v;
vector < int > gdje[N];

void postavi(){
	for(int i = 0;i < N;i++)
		for(int j = 0;j < 8;j++)
			dp[i][j & 1][!!(j & 2)][!!(j & 4)] = {-1, -1};
}

inline pii povec(pii A){
	return {A.X + 1, A.Y};
}

pii spoji(pii A, pii B){
	if(A.X == B.X) 
		return {A.X, add(A.Y, B.Y)};
	return max(A, B);
}


void dinamika(){
	for(int i = 0;i < 4;i++){
		dp[m][1][i & 1][!!(i & 2)] = {0, 1};
		dp[m][0][i & 1][!!(i & 2)] = {0, 0};
	}
	for(int i = m - 1;i >= 0;i--){
		for(int pos_L = 0;pos_L < 2;pos_L++){
			for(int mogu_L = 0;mogu_L < 2;mogu_L++){
				for(int mogu_R = 0;mogu_R < 2;mogu_R++){
					bool raz = ((i == m - 1) || v[i + 1].X != v[i].X);
					pii ret = dp[i + 1] [pos_L][mogu_L | raz][mogu_R | raz];
					if(mogu_L && L[i] <= gran)
						ret = spoji(ret, povec(dp[i + 1][pos_L | (L[i] == gran)][raz][mogu_R | raz]));
					if(mogu_R && R[i] > gran)
						ret = spoji(ret, povec(dp[i + 1][pos_L][mogu_L | raz][raz]));	
					dp[i][pos_L][mogu_L][mogu_R] = ret;
				}
			}
		}
	}
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0;i < n;i++){
		int x; scanf("%d", &x);
		gdje[x].PB(i);
	}
	for(int i = 0;i < m;i++){
		int x, y; scanf("%d%d", &x, &y);
		v.PB({x, y});
	}
	sort(v.begin(), v.end());
	for(int i = 0;i < m;i++){
		if(v[i].Y > (int)gdje[v[i].X].size()){
			L[i] = n, R[i] = -1; continue;
		}
		L[i] = gdje[v[i].X][v[i].Y - 1];
		R[i] = gdje[v[i].X][(int)gdje[v[i].X].size() - v[i].Y];
	}
	pii uk = {0, 0};
	for(gran = -1;gran < n;gran++){
		dinamika();
		uk = spoji(uk, dp[0][gran == -1][1][1]);
	}
	printf("%d %d\n", uk.X, uk.Y);
}