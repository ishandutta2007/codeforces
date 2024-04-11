//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;
string s;
int cor0[maxn], cor1[maxn], wro0[maxn], wro1[maxn];
int ans, n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	cin >> s;
	s = "*" + s;
	for(int i = 1; i <= n; i++){
		if(s[i] == '0'){
			cor0[i] = max(cor0[i - 1], cor1[i - 1] + 1);
			cor1[i] = cor1[i - 1];
			wro0[i] = max(wro0[i - 1], max(cor0[i - 1] + 1, wro1[i - 1] + 1));
			wro1[i] = wro1[i - 1];
		}
		else{
			cor0[i] = cor0[i - 1];
			cor1[i] = max(cor1[i - 1], cor0[i - 1] + 1);
			wro0[i] = wro0[i - 1];
			wro1[i] = max(wro1[i - 1], max(cor1[i - 1] + 1, wro0[i - 1] + 1));
		}
		ans = max(ans, max(max(cor0[i], cor1[i]), max(wro0[i], wro1[i])));
	}
	int c0 = 0, c1 = 0;
	for(int i = n; i > 0; i--){
		if(s[i] == '0')
			c0 = max(c0, c1 + 1);
		else
			c1 = max(c1, c0 + 1);
		ans = max(ans, max(c0 + max(wro0[i - 1], cor1[i - 1]), c1 + max(wro1[i - 1], cor0[i - 1])));
	}
	cout << ans << endl;
	return 0;
}