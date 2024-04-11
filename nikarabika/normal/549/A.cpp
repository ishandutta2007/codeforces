#include <bits/stdc++.h>

using namespace std;

const int maxn = 50 + 2;
char a[maxn][maxn];
string s = "face";
int n, m;

int main(){
	cin.tie(0);
	sort(s.begin(), s.end());
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> a[i][j];
	int ans = 0;
	for(int i = 1; i + 1 <= n; i++)
		for(int j = 1; j + 1 <= m; j++){
			string t = "";
			t = a[i][j];
			t += a[i][j + 1];
			t += a[i + 1][j];
			t += a[i + 1][j + 1];
			sort(t.begin(), t.end());
			ans += (t == s);
		}
	cout << ans << endl;
	return 0;
}