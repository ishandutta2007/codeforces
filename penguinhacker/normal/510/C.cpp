#include <bits/stdc++.h>
using namespace std;

int n;
string s[100];
vector<int> adj[26];

int color[26] = {0};
bool checkCyc(int u) {
    color[u] = 1;
    for (int v : adj[u]) {
        if (color[v] == 0) {
            if (checkCyc(v))
                return true;
        }
		else if (color[v] == 1)
            return true;
    }
    color[u] = 2;
    return false;
}

bool visited[26]={0};
vector<char> ans;
void dfs(int u) {
	visited[u] = 1;
	for (int v:adj[u])
		if (!visited[v])
			dfs(v);
	ans.push_back((char)('a'+u));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	bool pos = 1;
	cin >> n;
	for (int i=0; i<n; ++i) cin >> s[i];
	for (int i=0; i<n-1; ++i) {
		if (s[i].size()>s[i+1].size() && s[i].substr(0, s[i+1].size())==s[i+1]) {
			pos=0;
			break;
		}
		int x=min(s[i].size(), s[i+1].size());
		for (int j=0; j<x; ++j) {
			if (s[i][j]!=s[i+1][j]) {
				adj[s[i][j]-'a'].push_back(s[i+1][j]-'a');
				break;
			}
		}
	}
	
	//cycle detection
	for (int i=0; i<26; ++i) {
		if (color[i]==0 && checkCyc(i)) {
			pos = 0;
			break;
		}
	}
	if (!pos) {
		cout << "Impossible";
		return 0;
	}

	for (int i=0; i<26; ++i)
		if (!visited[i])
			dfs(i);

	reverse(ans.begin(), ans.end());
	for (char c:ans)
		cout << c;
	return 0;
}