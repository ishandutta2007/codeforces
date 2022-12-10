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

const int maxn = 1e6, maxsq = 1e3;
int x[maxn], y[maxn], ord[maxn];
int n;

bool cmp(int i, int j){
	if(x[i] / maxsq != x[j] / maxsq)
		return x[i] < x[j];
	return y[i] < y[j];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> x[i] >> y[i];
		x[i]--, y[i]--;
		ord[i] = i;
	}
	sort(ord, ord + n, cmp);
	for(int i = 0; i < n; i++)
		cout << ord[i] + 1 << ' ';
	cout << '\n';
	return 0;
}