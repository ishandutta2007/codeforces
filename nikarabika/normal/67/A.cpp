//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))

const int maxn = 1000 + 10;
int ans[maxn], n;
string s;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	cin >> s;
	ans[0] = 1;
	for(int i = 0; i + 1 < n; i++){
		if(s[i] == 'L'){
			ans[i + 1] = 1;
			int p = i;
			while(p >= 0 and ((s[p] == '=' and ans[p] != ans[p + 1]) or (s[p] == 'L' and ans[p] == ans[p + 1])))
				ans[p--]++;
		}
		else if(s[i] == '=')
			ans[i + 1] = ans[i];
		else
			ans[i + 1] = ans[i] + 1;
	}
	for(int i = 0; i < n; i++)
		cout << ans[i] << ' ';
	cout << endl;
	return 0;
}