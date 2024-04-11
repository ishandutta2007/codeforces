//sobskdrbhvk
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

const int maxn = 1e6 + 85 - 69;
int num[maxn * 2];
int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(num, -1, sizeof num);
	cin >> n;
	for(int i = 0; i < n; i++)
		num[i] = i;
	for(int i = 1; i <= n; i++){
		int lst = 0;
		for(int j = i - 1; j < n + i - 1; j += i)
			swap(lst, num[j]);
		num[n + i - 1] = lst;
	}
	for(int i = 0; i < n; i++)
		cout << num[n + i] + 1 << ' ';
	cout << '\n';
	return 0;
}