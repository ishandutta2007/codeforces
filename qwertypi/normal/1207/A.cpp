#include <iostream>
#include <vector>
#include <utility>

#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
#define fi first
#define se second

#define p1 1000000007

using namespace std;

typedef long long ll;

int main(){
	int t;
	cin >> t;
	for(int i=0;i<t;i++){
		int b, p, f;
		cin >> b >> p >> f;
		int h, c;
		cin >> h >> c;
		int ans = 0;
		b /= 2;
		if(h >= c){
			ans += min(b, p) * h;
			int k = min(b, p);
			b -= k;
			ans += min(b, f) * c;
		}else{
			ans += min(b, f) * c;
			int k = min(b, f);
			b -= k;
			ans += min(b, p) * h;
		}
		cout << ans << endl;
	}
	return 0;
}