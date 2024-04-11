#include <iostream>
#include <string>
#define inf (1LL << 30)
typedef long long ll;
using namespace std;

ll dp[701][701];
ll A[500001];
int main(){
	fill(A, A+500001, 0);
	ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while(q--){
		int t, x, y;
		cin >> t >> x >> y;
		if(t == 1){
			A[x] += y;
			for(int i=1;i<=700;i++){
				dp[i][(x % i)] += y;
			}
		}else{
			if(x > 700){
				ll ans = 0;
				for(int i=y;i<=500000;i += x){
					ans += A[i];
				}
				cout << ans << endl;
			}else{
				cout << dp[x][y] << endl;
			}
		}
	}
}