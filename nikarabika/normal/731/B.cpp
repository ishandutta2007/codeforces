//sobskdrbhvk
//remember the flight, the bird dies ):(
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

const int maxn = 2e5 + 85 - 69;
int a[maxn],
	sum[maxn],
	n;

bool solve(int st){
	if(st >= n) return true;
	int en = find(a + st, a + n, 0) - a;
	return solve(en + 1) and (sum[en] - sum[st]) % 2 == 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i], sum[i + 1] = sum[i] + a[i];
	if(solve(0))
		cout << "YES";
	else
		cout << "NO";
	return 0;
}