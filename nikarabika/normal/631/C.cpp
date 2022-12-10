//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
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
	b[maxn],
	ty[maxn],
	ans[maxn],
	Max[maxn],
	n, m;

int fmax(int i, int j){
	return max(MP(b[i], i), MP(b[j], j)).R;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < m; i++)
		cin >> ty[i] >> b[i], ty[i]--;
	b[m] = -1;
	Max[m] = m;
	for(int i = m - 1; i >= 0; i--)
		Max[i] = fmax(Max[i + 1], i);
	
	int p = Max[0];
	sort(a, a + b[p]);

	int ansptr = n - 1, ptr1 = n - 1, ptr0 = 0;
	while(ansptr >= b[p])
		ans[ansptr--] = a[ptr1--];
	int lastp;
	while(ansptr >= 0){
		if(ansptr == b[p] - 1)
			lastp = p, p = Max[p + 1];
		if(!ty[lastp])
			ans[ansptr--] = a[ptr1--];
		else
			ans[ansptr--] = a[ptr0++];
	}
	for(int i = 0; i < n; i++)
		cout << ans[i] << ' ';
	cout << '\n';
	return 0;
}