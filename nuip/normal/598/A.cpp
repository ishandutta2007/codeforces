#include<bits/stdc++.h>

using namespace std;

#define rep(i,j) for(int i=0;i<(j);i++)

typedef pair<int,int> pii;
typedef long long ll;

int main(){
	int t;
	ll n,ans,sq;
	cin >> t;
	while(t--){
		cin >> n;
		ans = (n+1)*n/2;
		sq = 1;
		while(sq<=n){
			ans -= 2*sq;
			sq *= 2;
			//cout << ans << endl;
		}
		cout << ans << endl;
	}
	return 0;
}