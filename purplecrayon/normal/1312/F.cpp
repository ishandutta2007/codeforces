// 23:45 - 00:01
#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define lch (o << 1)
#define rch (o << 1 | 1)

typedef double db;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> pint;

const int N = 3e5 + 5;
const int M = 300 + 5;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;

int f[M][5];
int g;
int b[5];

void Init(){
	f[0][1] = f[0][2] = f[0][3] = 0;
	
	for(int i=1; i<M; i++){
		for(int c=1; c<=3; c++){
			set<int> s;
			for(int d=1; d<=3; d++){
				int j = max(i - b[d], 0);
				if(d > 1 && c == d) continue;
				s.insert(f[j][d]);
			}
			int mex = 0;
			while(s.find(mex) != s.end()) mex++;
			f[i][c] = mex;
		}
	}
}

void FindCycle(){
	for(g = M / 2; g >= 1; g--){
		bool flag = 1;
		for(int i = M - 2 * g; i < M - g; i++){
			int j = i + g;
			for(int c=1; c<=3; c++)
				if(f[i][c] != f[j][c]){
					flag = 0; break;
				}
			if(!flag) break;
		}
		if(flag) break;
	}
}

int SG(ll n, int op){
	if(n < M) return f[n][op];
	ll det = (((M-1) % g - n % g) % g + g) % g;
	return f[(M-1) - det][op];
}

ll a[N];

int Solve(){
	int n;
	cin >> n >> b[1] >> b[2] >> b[3];
	for(int i=1; i<=n; i++)
		cin >> a[i];

	Init();
	FindCycle();

	int sg = 0;
	for(int i=1; i<=n; i++)
		sg ^= SG(a[i], 1);

	int ans = 0;
	for(int i=1; i<=n; i++){
		int nsg = SG(a[i], 1);
		sg ^= nsg;
		for(int d=1; d<=3; d++){
			ll j = max(a[i] - b[d], 0LL);
			if((sg ^ SG(j, d)) == 0) ans++;
		}
		sg ^= nsg;
	}

	return ans;
}

int main(){
	ios::sync_with_stdio(0);

	int t; cin >> t;
	while(t--)
		cout << Solve() << endl;

	return 0;
}