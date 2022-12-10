//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

//man am A _____ & a pair of Izzz wayTn' 230u :)

typedef pair<int, int> pii;

#define L second
#define R first

const int maxn = 5e5 + 85 - 69;
pii a[maxn];
int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i].L >> a[i].R;
	sort(a, a + n);
	int Max = 0, ans = 0;
	for(int i = 0; i < n; i++)
		if(a[i].L > Max)
			ans++, Max = a[i].R;
	cout << ans << endl;
	return 0;
}