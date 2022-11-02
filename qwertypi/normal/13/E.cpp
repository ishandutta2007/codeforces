#include <bits/stdc++.h>

using namespace std;

const int B = 400;
const int N = 1e5 + 13;
int A[N];
int nxt[N];
int dp[2][N];
struct query{
	int t, a, b;
};

vector<query> Q;

bool sp[N];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, q;
	cin >> n >> q;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	for(int i = 0; i < q; i++){
		int t, a, b;
		cin >> t;
		if(t == 0){
			cin >> a >> b;
		}else{
			cin >> a;
		}
		a--;
		Q.push_back({t, a, b});
	}
	for(int b = 0; b < (q + B - 1) / B; b++){
		fill(sp, sp + N, 0);
		for(int i = 0; i < 2; i++) fill(dp[i], dp[i] + n, (1 << 30));
		for(int i = 0; i < n; i++){
			nxt[i] = min(n, i + A[i]);
		}
		sp[n] = true;
		for(int i = b * B; i < min(q, (b + 1) * B); i++){
			if(Q[i].t == 0) sp[Q[i].a] = true;
		}
		for(int i = n - 1; i >= 0; i--){
			if(sp[i] || nxt[i] == n){
				dp[0][i] = 0;
				dp[1][i] = i;
			}else{
				dp[0][i] = 1 + dp[0][nxt[i]];
				dp[1][i] = dp[1][nxt[i]];
			}
		}
		for(int i = b * B; i < min(q, (b + 1) * B); i++){
			if(Q[i].t == 0){
				A[Q[i].a] = Q[i].b;
			}else{
				int a1 = Q[i].a, a2 = 0;
				while(true){
					a2 += dp[0][a1]; a1 = dp[1][a1];
					if(a1 + A[a1] >= n) {
						a2++; break;
					}else{
						a1 += A[a1]; a2++;
					}
				}
				cout << a1 + 1 << ' ' << a2 << endl;
			}
		}
	}
}