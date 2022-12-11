#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;
typedef double db;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 9;
ll ln[N];

int main(){
	fastIO;
	int n, m, l;
	cin >> n >> m >> l;
	ln[0] = -1;
	ln[n + 1] = -1;
	for(int i = 1; i <= n; i ++ )	
		cin >> ln[i];
	int ans = 0;
	for(int i = 1; i <= n; i ++ ){
		if(ln[i] > l and ln[i - 1] <= l){
			ans ++;
		}
	}
	int t;
	int p, d;
	for(int i = 0 ; i < m ;i  ++ ){
		cin >> t;
		if(t == 0){
			cout << ans << "\n";
		}
		else{
			cin >> p >> d;
			if(ln[p] <= l){
				ln[p] += d;
				if(ln[p] > l){
					ans ++ ;
					if(ln[p - 1] > l){
						ans -- ;
					}
					if(ln[p + 1] > l){
						ans -- ;
					}
				}
			}
			else{
				ln[p] += d;
			}
		}
	}
	return 0;
}