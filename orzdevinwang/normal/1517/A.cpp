#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j), i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = k; i >= i##E; i--)
#define mkp make_pair
#define pii pair<int, int>
#define ll long long
#define db double
#define sz(a) a.size()
#define x first
#define y second
#define vi vector<int>
using namespace std;
const int N = 1e6 + 7, z = 2050;
int m, a[N]; 
ll n;
void rmain() {
	cin >> n;
	if(n % z) 
		cout << "-1\n";
	else {
		n /= z;
		int sum = 0;
		while(n) sum += n % 10, n /= 10;
		cout<< sum << "\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while(T--) rmain();
	return 0;
}