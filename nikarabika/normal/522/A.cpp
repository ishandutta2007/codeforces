#include <bits/stdc++.h>

using namespace std;

#define PB push_back

const int maxn = 269;
string s[maxn];
int par[maxn], n;
vector<int> v[maxn];

int dfs(int x){
	int ans = 1;
	for(auto y : v[x])
		ans = max(ans, dfs(y) + 1);
	return ans;
}

int Find(string t){
	for(int i = 0; 1; i++)
		if(s[i] == t)
			return i;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	s[0] = "polycarp";
	for(int i = 1; i <= n; i++){
		string t;
		cin >> s[i] >> t >> t;
		for(int j = 0; j < s[i].size(); j++)
			if(s[i][j] <= 'Z')
				s[i][j] = s[i][j] - 'A' + 'a';
		for(int j = 0; j < t.size(); j++)
			if(t[j] <= 'Z')
				t[j] = t[j] - 'A' + 'a';
		par[i] = Find(t);
		v[par[i]].PB(i);
	}
	par[0] = -1;
	cout << dfs(0) << endl;
	return 0;
}