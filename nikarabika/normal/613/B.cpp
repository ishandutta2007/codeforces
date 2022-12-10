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

const int maxn = 1e5 + 85 - 69;
LL a[maxn], b[maxn], order[maxn], sum[maxn];
LL A, cf, cm, m, n;

bool cmp(int i, int j){
	return a[i] < a[j];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> A >> cf >> cm >> m;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		order[i] = i;
	}
	sort(order, order + n, cmp);
	for(int i = 0; i < n; i++)
		b[i] = a[order[i]];
	for(int i = 0; i < n; i++)
		sum[i + 1] = sum[i] + b[i];
	LL Max = -1, Maxlo, Maxperf;
	for(LL perf = 0; perf <= n; perf++){
		LL cost = m - (A * perf - (sum[n] - sum[n - perf]));
		if(cost < 0)
			continue;
		LL lo = a[order[0]], hi = A;
		if(perf == n){
			lo = A;
			goto hell;
		}
		while(hi - lo > 1){
			LL mid = (lo + hi) >> 1;
			int id = lower_bound(b, b + n - perf, mid) - b;
			//cout << "BS " << mid << ' ' << id * mid - sum[id] << endl;
			if(id * mid - sum[id] <= cost)
				lo = mid;
			else
				hi = mid;
		}
hell:
		if(lo * cm + perf * cf >= Max){
			Max = lo * cm + perf * cf;
			Maxlo = lo;
			Maxperf = perf;
		}
	//	cout << perf << ' ' << lo << endl;
	}
	for(int i = 1; i <= Maxperf; i++)
		b[n - i] = A;
	for(int j = 0; j < n - Maxperf and b[j] < Maxlo; j++)
		b[j] = Maxlo;
	for(int i = 0; i < n; i++)
		a[order[i]] = b[i];
	cout << Max << '\n';
	for(int i = 0; i < n; i++)
		cout << a[i] << ' ';
	cout << '\n';
	return 0;
}