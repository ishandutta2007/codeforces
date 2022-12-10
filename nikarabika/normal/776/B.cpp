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

const int maxn = 1e6;
bool isp[maxn];
int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(isp, true, sizeof isp);
	isp[0] = isp[1] = false;
	for(int i = 0; i < maxn; i++)
		if(isp[i])
			for(int j = i + i; j < maxn; j += i)
				isp[j] = false;
	cin >> n;
	if(n >= 3) cout << 2 << '\n';
	else
		cout << 1 << '\n';
	for(int i = 0; i < n; i++)
		if(isp[i + 2])
			cout << 1 << ' ';
		else
			cout << 2 << ' ';
	return 0;
}