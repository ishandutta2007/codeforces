#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++)
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) ((int) a.size())
#define vi vector<int>
using namespace std;
const int N = 2e6 + 7;
int n, m, col[N], pr[N];	
int ehd[N], ev[N], enx[N], eid;
void eadd(int u, int v) {
	++eid, enx[eid] = ehd[u], ev[eid] = v, ehd[u] = eid;
}
void dfs(int x) {
	for(int i = ehd[x]; i; i = enx[i]) if(!col[ev[i]])
		col[ev[i]] = 3 - col[x], dfs(ev[i]);
}
int main() {  
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	if(n % 2 == 0) {
		cout << "First\n";
		L(i, 1, n * 2) cout << (i - 1) % n + 1 << " ";
		cout << endl;
	}
	else {
		cout << "Second" << endl;
		L(i, 1, n) eadd(i, i + n), eadd(i + n, i);
		L(i, 1, n * 2) {
			int x;
			cin >> x;
			if(pr[x]) eadd(i, pr[x]), eadd(pr[x], i);
			pr[x] = i;
		} 
		L(i, 1, n * 2) if(!col[i]) col[i] = 1, dfs(i);
		int sum = 0;
		L(i, 1, n * 2) if(col[i] == 1) sum += i, sum = sum >= 2 * n ? sum - 2 * n : sum;
		if(sum == 0) {
			L(i, 1, n * 2) if(col[i] == 1) cout << i << ' ';
		}
		else {
			L(i, 1, n * 2) if(col[i] == 2) cout << i << ' ';	
		}
		cout << endl;
	}
	return 0;
}