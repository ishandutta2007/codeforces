#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++)
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) ((int) a.size())
#define vi vector<int>
using namespace std;
const int N = 2005;
int n, dep[N], f[N], ns1[N], ns2[N], tp;
void Main() {
	cin >> n;
	cout << "? 1" << endl;
	L(i, 1, n) cin >> dep[i];
	L(i, 1, n) f[dep[i]]++;
	int sum = 0, mn = 0;
	L(i, 1, n) if(i % 2 == 0) sum += f[i];
	if(sum > n - 1 - sum) mn = true;
	if(mn == false) {
		L(i, 1, n) if(dep[i] == 1) ++tp, ns1[tp] = 1, ns2[tp] = i;
	}
	L(i, 2, n) if(dep[i] % 2 == mn) {
		cout << "? " << i << endl;
		int u;
		L(j, 1, n) {
			cin >> u;
			if(u == 1) ++tp, ns1[tp] = i, ns2[tp] = j;	
		}
	}
	cout << "!" << endl;
	L(i, 1, tp) cout << ns1[i] << " " << ns2[i] << endl;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0); 
	Main(); 
	return 0;
}