#include <iostream>
#include <stack>
#include <vector>

#define N 110
#define SIGMA 26

using namespace std;

typedef pair<char, char> PCC;

vector<int> adj[SIGMA];

string str[N];
int n;

stack<int> stk;
int pass[SIGMA], pos[SIGMA];

void dfs_topo(int u) {
	if(pass[u]) {
		return;
	}
	pass[u] = 1;
	for(int i = 0;i < adj[u].size();i++) {
		int v = adj[u][i];
		dfs_topo(v);
	}
	stk.push(u);
}
PCC cmp(string &s1, string &s2) {
	for(int i = 0;s1[i] && s2[i];i++) {
		if(s1[i] != s2[i]) {
			return {s1[i], s2[i]};
		}
	}
	if(s1.length() > s2.length()) {
		return {1, 1};
	}
	return {2, 2};
}
int main() {
	cin >> n;
	for(int i = 0;i < n;i++) {
		cin >> str[i];
	}
	for(int i = 0;i < n;i++) {
		for(int j = i+1;j < n;j++) {
			PCC data = cmp(str[i], str[j]);
			if(data.first == 1) {
				cout << "Impossible" << endl;
				return 0;
			}
			if(data.first == 2) {
				continue;
			}
			adj[data.first-'a'].push_back(data.second-'a');
		}
	}
	for(int i = 0;i < SIGMA;i++) {
		pass[i] = 0;
	}
	for(int i = 0;i < SIGMA;i++) {
		dfs_topo(i);
	}
	string topo = "";
	while(!stk.empty()) {
		char c = stk.top() + 'a';
		topo += c;
		stk.pop();
	}
	for(int i = 0;topo[i];i++) {
		pos[topo[i]-'a'] = i;
	}
	for(int i = 0;i < n;i++) {
		for(int j = i+1;j < n;j++) {
			PCC data = cmp(str[i], str[j]);
			if(data.first == 2) {
				continue;
			}
			if(pos[data.first-'a'] > pos[data.second-'a']) {
				cout << "Impossible" << endl;
				return 0;
			}
		}
	}
	cout << topo << endl;
	return 0;
}