#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		bool vis[60][60]={};
		string st;
		int x;
		cin >> st >> x;
		int h=stoi(st.substr(0, 2)), m=stoi(st.substr(3));
		int ans=0;
		while(!vis[h][m]) {
			vis[h][m]=1;
			if (h<10&&m==10*h)
				++ans;
			else if (h>=10) {
				if (10*(h%10)+h/10==m)
					++ans;
			}
			h+=x/60;
			m+=x%60;
			if (m>=60) {
				m-=60;
				++h;
			}
			h%=24;
		}
		cout << ans << "\n";
	}
	return 0;
}