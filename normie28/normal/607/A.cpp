#include <iostream> 
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
#define what_is(x) cerr << #x << " is " << x << endl;
#define IOS ios::sync_with_stdio(false); cin.tie(0);
typedef long long ll;
const int N = 1e5+5;
const int INF = 1e9;
const int MOD = 1e9+7;
int n;
pair<int,int> bea[N];
int f[N]; //f[i]: nuber of beacons that could be destroyed if 
//beacon[i] is the first activate (k tinh phia sau)
int main()
{
	IOS
	// freopen("input.txt", "r", stdin);
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> bea[i].first >> bea[i].second;
	}
	sort(bea, bea + n);
	f[0] = 0;
	for(int i=1; i<n; i++){
		pair<int,int> r;
		r.first = bea[i].first - bea[i].second;
		//find the right most beacon has position < r
		int idx = lower_bound(bea, bea+i, r) - bea;
		if (idx - 1 < 0) f[i] = i; //destroyed all except a[i]
		else f[i] = f[idx-1] + i-idx;
	}
	int ans = INF;
	for(int i=0; i<n; i++){
		ans = min(ans, f[i] + n-i-1);
	}
	cout << ans << endl;
	return 0;
}