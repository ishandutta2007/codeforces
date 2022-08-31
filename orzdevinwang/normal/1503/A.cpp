#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define pii pair<int, int>
#define db double
#define x first
#define y second
#define ull unsigned long long
#define sz(a) ((int) (a).size())
#define vi vector<int>
using namespace std;
const int N = 5e6 + 7;
int n, a[N], b[N], now[N];
char s[N];
void Main() {
	cin >> n >> (s + 1);
	int cnt = 0, cnt0 = 0, cnt1 = 0;
	L(i, 1, n) if(s[i] == '1') cnt ++;
	cnt /= 2;
	L(i, 1, n) if(s[i] == '1') {
		if(cnt) now[i] = 1, --cnt;
		else now[i] = -1;
	}
	L(i, 1, n) {
		if(s[i] == '0') {
			if(cnt0 < cnt1) a[i] = 1, b[i] = -1, cnt0 ++, cnt1 --;
			else a[i] = -1, b[i] = 1, cnt0 --, cnt1 ++;
		}
		else {
			cnt0 += now[i], cnt1 += now[i];
			a[i] = b[i] = now[i];
		}
		if(cnt0 < 0 || cnt1 < 0) {
			cout << "NO\n";
			return;
		} 
	}
	if(cnt0 || cnt1) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	L(i, 1, n) cout << (a[i] == 1 ? '(' : ')');
	cout << "\n";
	L(i, 1, n) cout << (b[i] == 1 ? '(' : ')');
	cout << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while(T--) Main();
	return 0;
}