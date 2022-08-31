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
	cin >> n;
	int m = n * n;
	queue<pii> q1, q2;
	L(i, 1, n) L(j, 1, n) if((i + j) & 1) q1.push(pii(i, j)); else q2.push(pii(i, j));
	while(m --) {
		int col;
		cin >> col;
		if(col == 1) {
			if(q2.empty()) {
				pii u = q1.front();
				cout << 3 << " " << u.x << " " << u.y << endl;
				q1.pop();	
			}
			else {
				pii u = q2.front();
				cout << 2 << " " << u.x << " " << u.y << endl;
				q2.pop();
			}
		} 
		else {
			if(q1.empty()) {
				pii u = q2.front();
				cout << 5 - col << " " << u.x << " " << u.y << endl;
				q2.pop();
			}
			else {
				pii u = q1.front();
				cout << 1 << " " << u.x << " " << u.y << endl;
				q1.pop();
			}
		}
		fflush(stdout);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	Main();
	return 0;
}