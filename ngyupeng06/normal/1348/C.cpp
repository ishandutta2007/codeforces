#include <bits/stdc++.h>

using namespace std;
typedef long long int li;
typedef pair<int,int> pii;
typedef pair<li,li> pll;
#define mp make_pair
#define pb push_back

long long t, n, m, a, b, c, d, e, f, k;
string arr[100005], s;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--){
		cin >> n >> k;
		for (int i=0; i<k; i++){
			arr[i] = "";
		}
		cin >> s;
		sort(s.begin(), s.end());
		//cout << s << "\n";
		char ch = s[0];
		if (ch == s[n-1]){
			int xx = n/k;
			if (n%k != 0) xx++;
			for (int i=0; i<xx; i++) cout << ch;
			cout << "\n";
			continue;
		}
		if (s[0] == s[k-1] && s[k] == s[n-1]){
			int xx = n/k;
			if (n%k != 0) xx++;
			xx--;
			cout << ch;
			for (int i=0; i<xx; i++) cout << s[k];
			cout << "\n";
			continue;
		}
		bool chch = true;
		string ans;
		for (int i=0; i<n; i++){
			if (i < k && s[i] != ch){
				ans = s[k-1];
				chch = false;
				break;
			}
			else if (i < k){
				arr[i] += s[i];
			}
			else {
				arr[0] += s[i];
			}
		}
		if (!chch) cout << ans << "\n";
		else cout << arr[0] << "\n";
	}
}