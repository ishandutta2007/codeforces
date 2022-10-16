#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;

const int N = 1e5 + 500;
const int OFF = (1 << 17);
const int MOD = 777777777;

inline int add(int A, int B){
	if(A + B >= MOD)
		return A + B - MOD;
	return A + B;
}

inline int mul(int A, int B){
	return (ll)A * B % MOD;
}

struct node{
	int dp[3][3], NISTA = 0;
	node(){
		memset(dp, 0, sizeof(dp));
	}
	node(int x){
		memset(dp, 0, sizeof(dp));
		if(x != -1){
			dp[x][x] = 1;
		}
		else{
			for(int i = 0;i < 3;i++)
				dp[i][i] = 1;
		}
	}
	int ukupno(){
		int ret = 0;
		for(int i = 0;i < 3;i++)
			for(int j = 0;j < 3;j++)
				ret = add(ret, dp[i][j]);
		return ret;
	}
};

node T[2 * OFF], NULA;
int mogu[3][3], n, q;

const node operator+ (const node &L, const node &R){
	if(R.NISTA) return L;
	if(L.NISTA) return R;
	node ret;
	for(int a = 0;a < 3;a++)
		for(int b = 0;b < 3;b++)
			if(mogu[a][b])
				for(int c = 0;c < 3;c++)
					for(int d = 0;d < 3;d++)
						ret.dp[c][d] = add(mul(L.dp[c][a], R.dp[b][d]), ret.dp[c][d]);
	return ret;
}

void update(int i, int x){
	T[OFF + i] = node(x);
	for(i = (OFF + i) / 2; i ; i /= 2)
		T[i] = T[2 * i] + T[2 * i + 1];
}

int main(){
	NULA.NISTA = 1;
	scanf("%d%d", &n, &q);
	for(int i = 0;i < 3;i++)
		for(int j = 0;j < 3;j++)
			scanf("%d", &mogu[i][j]);
	for(int i = 0;i < OFF;i++){
		if(i < n)
			T[OFF + i] = node(-1);
		else
			T[OFF + i] = NULA;
	}
	for(int i = OFF - 1; i ; i--)
		T[i] = T[2 * i] + T[2 * i + 1];
	for(;q--;){
		int pos, nw; scanf("%d%d", &pos, &nw);
		update(pos - 1, nw - 1);
		printf("%d\n", T[1].ukupno());
	}
}