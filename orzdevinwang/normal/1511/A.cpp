#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define pii pair<int, int>
#define db double
#define x first
#define y second
#define sz(a) ((int) (a).size())
#define mkp make_pair
#define vi vector<int>
using namespace std;
const int N = 5e5 + 7;
int n, m, ns, a[N];
int rmain() {
    cin >> n, ns = n;
    L(i, 1, n) cin >> a[i], ns -= (a[i] == 2);
    cout << ns << "\n";
    return 0;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while(T--) rmain();	
	return 0;
} 
// To Cheat, To attack!