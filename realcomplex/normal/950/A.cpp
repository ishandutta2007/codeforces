#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define TEST freopen("in.txt","r",stdin);
#define ab(a) ((a < 0) ? (-(a)) : (a))
//8dsaufsakhalkfsahjlfsakfsa
//fsajfahsfsahfsajfsahfsa
int main(){
	int l,r,a;
	while(cin >> l >> r >> a){
		int k = ab(l-r);
		if(a <= k){
			cout << (min(l,r) + a)* 2 << "\n";
		}
		else{
			cout << (max(l,r) + ((a-k) / 2)) * 2 << "\n";
		}
	}
	return 0;
}