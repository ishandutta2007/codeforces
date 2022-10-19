#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n , cnt_id; char c[N];
vector <int> v[N] , id[2] , ve[2][2];

void solve() {
	if(!ve[0][0].empty() || !ve[1][1].empty()) return;
	if(ve[0][1].empty() || ve[1][0].empty()) return;
	int a = ve[0][1].back() , b = ve[1][0].back();
	if(v[a].back() < v[b].back()) v[a].push_back(v[b].back()) , v[b].pop_back();
	else v[b].push_back(v[a].back()) , v[a].pop_back();
	ve[0][1].pop_back() , ve[1][0].pop_back();
	ve[0][0].push_back(a) , ve[1][1].push_back(b);
}

void print(int x) {
	for(auto i : v[x]) printf("%d " , i);
}

int main() {
	scanf("%s" , c + 1) , n = strlen(c + 1);
	for(int i = 1; i <= n; i++) {
		int s = c[i] == 'R';
		if(id[s ^ 1].empty()) id[s ^ 1].push_back(++cnt_id);
		int t = id[s ^ 1].back(); id[s ^ 1].pop_back();
		v[t].push_back(i) , id[s].push_back(t);
	}
	printf("%d\n" , cnt_id - 1);
	for(int i = 1; i <= cnt_id; i++)
		ve[c[v[i][0]] == 'R'][c[v[i][v[i].size() - 1]] == 'R'].push_back(i);
	solve();
	int t = ve[1][1].size() != ve[0][0].size() ? ve[1][1].size() > ve[0][0].size() : ve[1][0].size() > ve[0][1].size();
	while(ve[t][t ^ 1].size()) print(ve[t][t ^ 1].back()) , ve[t][t ^ 1].pop_back();
	while(ve[t][t].size()) {
		print(ve[t][t].back()) , ve[t][t].pop_back();
		while(ve[t ^ 1][t].size()) print(ve[t ^ 1][t].back()) , ve[t ^ 1][t].pop_back();
		t ^= 1;
	}
	printf("\n");
	return 0;
}