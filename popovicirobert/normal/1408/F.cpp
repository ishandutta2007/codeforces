#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "
 
 
using namespace std;

vector<pair<int, int>> sol;

void divide(int l, int r, vector<int>& a) {
	if(l == r) return ;
	if(l + 1 == r) {
		sol.push_back({l, r});
		return ;
	}

	int mid = (l + r) / 2;
	divide(l, mid, a);
	divide(mid + 1, r, a);

	for(int i = l; i <= mid; i++) {
		sol.push_back({i, i - l + mid + 1});
	}
}

int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

	cin >> n;
	vector<int> a(n + 1);
	iota(a.begin(), a.end(), 0);

	int pw = 1;
	while(pw <= n) {
		pw *= 2;
	}
	pw /= 2;
    
    divide(1, pw, a);
    if(pw != n) {
    	divide(n - pw + 1, n, a);
	}

    assert((int)sol.size() <= (int)5e5);
    cout << (int)sol.size() << "\n";
    for(auto it : sol) {
    	cout << it.first << " " << it.second << "\n";
    }
    

    return 0;
}