#include <bits/stdc++.h>

using namespace std;

int prec[2001];
int ans[101];
int A[200000];
vector<pair<int, int>> sorted;
vector<map<int, vector<int>>> query(101);
set<int> B;
int main(){
	int n, m;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
		sorted.push_back({(int) 1e9 + 1 - A[i], i});
	}
	cin >> m;
	sort(sorted.begin(), sorted.end());
	for(int i = 0; i < m; i++){
		int v1, v2;
		cin >> v1 >> v2;
		v2--;
		query[v1][v2].push_back(i);
	}
	for(int i = 0; i < n; i++){
		B.insert(sorted[i].second);
		int prev = 0;
		auto ptr = B.begin();
		for(auto j : query[i + 1]){
			for(int i = prev; i < j.first; i++){
				ptr++;
			}
			prev = j.first;
			for(auto k : j.second){
				ans[k] = *ptr;
			}
		}
	}
	for(int i = 0; i < m; i++){
		cout << A[ans[i]] << endl;
	}
}