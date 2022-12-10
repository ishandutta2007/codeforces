//sobskdrbhvk
//remember the flying, the bird dies ):(
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int pos = 0;
	for(int i = 0; i < n; i++){
		int fi;
		string se;
		cin >> fi >> se;
		if(se == "South")
			pos += fi;
		else if(se == "North")
			pos -= fi;
		else if(pos == 0 or pos == 20000){
			cout << "NO" <<endl;
			return 0;
		}
		if(pos < 0 or pos > 20000){
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << (pos ? "NO" : "YES") << endl;
	return 0;
}