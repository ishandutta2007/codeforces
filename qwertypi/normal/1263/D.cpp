#include <bits/stdc++.h>
#pragma optimize("Ofast")
using namespace std;

bool A[200000][26];

int Size[300000], par[300000];
int root(int x){
	if(x == par[x]) return x;
	return par[x] = root(par[x]);
}

inline bool join(int x, int y){
	if(x == -1){
		return false;
	}
	int root_x = root(x), root_y = root(y);
	if(root_x == root_y){
		return false;
	}
	if(Size[root_x] > Size[root_y]){
		swap(root_x, root_y);
	}
	par[root_x] = root_y;
	Size[root_y] += Size[root_x];
}

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		for(auto j : s){
			A[i][j - 'a'] = 1;
		}
		Size[i] = 1;
		par[i] = i;
	}
	for(int i = 0; i < 26; i++){
		int prev = -1;
		for(int j = 0; j < n; j++){
			if(A[j][i]){
				join(prev, j);
				prev = j;
			}
		}
	}
	int ans = 0;
	set<int> cnt;
	for(int i = 0; i < n; i++){
		cnt.insert(root(i));
	}
	cout << cnt.size() << endl;
}