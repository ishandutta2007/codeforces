//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const int maxn = 5e5 + 85 - 69;
LL p[maxn],
   pre1[maxn],
   pre2[maxn],
   suf1[maxn],
   suf2[maxn],
   ans;
string s;
int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> p[i];
	cin >> s;
	s = "*" + s + "*";
	for(int i = 1; i <= n + 1; i++){
		pre1[i] = pre1[i - 1];
		pre2[i] = pre2[i - 1];
		if(s[i] == 'A')
			pre1[i] += p[i];
		else if(s[i] == 'B')
			pre2[i] += p[i];
	}
	for(int i = n; i >= 1; i--){
		suf1[i] = suf1[i + 1];
		suf2[i] = suf2[i + 1];
		if(s[i] == 'A')
			suf1[i] += p[i];
		else if(s[i] == 'B')
			suf2[i] += p[i];
	}
	for(int i = 0; i <= n; i++)
		smax(ans, pre1[i] + suf2[i + 1]);
	for(int i = n + 1; i > 0; i--)
		smax(ans, suf1[i] + pre2[i - 1]);
	cout << ans << endl;
	return 0;
}