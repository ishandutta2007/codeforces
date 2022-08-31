#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++) 
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) a.size()
#define vi vector<int>
using namespace std;
const int N = 1e5 + 7;
int r, b, d;
void Main() {
	cin >> r >> b >> d;
	if(r < b) swap(r, b);
	if((ll) b * (d + 1) < r) cout << "NO\n";
	else cout << "YES\n";
	
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	int T;
	cin >> T;
	while(T--) Main();
	return 0;
}