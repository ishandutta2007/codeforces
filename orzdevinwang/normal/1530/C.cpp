#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
using namespace std;
const int N = 4e5 + 7;
int n, a[N], b[N];
ll suma[N], sumb[N]; 
bool check (int x) {
	return 100 * x + suma[n] - suma[(n + x) / 4] >= sumb[n + x - (n + x) / 4];
} 
void Main () {
	cin >> n;
	L(i, 1, n) cin >> a[i];
	L(i, 1, n) cin >> b[i];
	sort(a + 1, a + n + 1);	
	sort(b + 1, b + n + 1), reverse(b + 1, b + n + 1);
	
	L(i, n + 1, n * 4) a[i] = b[i] = 0; 
	L(i, 1, n * 4) 
		sumb[i] = sumb[i - 1] + b[i], 
		suma[i] = suma[i - 1] + a[i];
	
	int l = 0, r = n * 3, ns = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if(check(mid)) ns = mid, r = mid - 1;
		else l = mid + 1;
	}
	cout << ns << "\n";
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	int T;
	cin >> T;
	while (T--) Main(); 
	return 0;
}