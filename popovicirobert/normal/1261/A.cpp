#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lsb(x) (x & (-x))
#define uint unsigned int


    
using namespace std;


  
int main() {
#ifdef HOME
    ifstream cin("A.in");
    //ofstream cout("A.out");
#endif
	int t, i;
    ios::sync_with_stdio(false);
   	cin.tie(0), cout.tie(0);
	
	cin >> t;
	
	while(t--) {
		int n, k;
		cin >> n >> k;
		
		string str;
		cin >> str;
		str = " " + str;
		
		vector < pair <int, int> > sol;
		
		for(i = 1; i <= 2 * (k - 1); i++) {
			char ch;
			if(i & 1) {
				ch = '(';
			}
			else {
				ch = ')';
			}
			int j = i;
			while(j <= n && str[j] != ch) {
				j++;
			}
			reverse(str.begin() + i, str.begin() + j + 1);
			sol.push_back({i, j});
		}
		for(i = 2 * (k - 1) + 1; i <= n; i++) {
			char ch;
			if(i <= 2 * (k - 1) + n / 2 - k + 1) {
				ch = '(';
			}
			else {
				ch = ')';
			}
			int j = i;
			while(j <= n && str[j] != ch) {
				j++;
			}
			reverse(str.begin() + i, str.begin() + j + 1);
			sol.push_back({i, j});
		}
		
		cout << sol.size() << "\n";
		for(auto it : sol) {
			cout << it.first << " " << it.second << "\n";
		}
		cout << "\n";
	}
	
	return 0;
}