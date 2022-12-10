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
	int n, len;
	cin >> n, len = 2 * n - 1;
	int a[len], sum = 0;
	int neg = 0;
	for(int i = 0; i < len; i++){
		cin >> a[i];
		if(a[i] < 0) a[i] = -a[i], neg++;
		sum += a[i];
	}
	if((n&1) or !(neg&1))
		cout << sum << endl;
	else
		cout << sum - 2**min_element(a, a + len) << endl;
	return 0;
}