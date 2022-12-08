						/* in the name of Allah */
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

#define P pair<int, int>

int n;
bool mat[1010][1010];
bool mark[1010];
vector <P> ad, del;

void dfs(int num, int par){
	mark[num] = true;
	for(int i = 0; i < n; i++){
		if(mat[num][i]){
			if(!mark[i])
				dfs(i, num);
			else if(i != par && i > num)
				del.push_back(P(num + 1, i + 1));
		}
	}
}

int main(){
	cin >> n;
	int a, b;
	for(int i = 0; i < n - 1; i++){
		cin >> a >> b;
		a--, b--;
		mat[a][b] = mat[b][a] = true;
	}
	dfs(0, -1);
	for(int i = 1; i < n; i++){
		if(!mark[i]){
			dfs(i, -1);
			ad.push_back(P(1, i + 1));
		}
	}
	cout << ad.size() << endl;
	for(int i = 0; i < ad.size(); i++)
		cout << del[i].first << ' ' << del[i].second << ' ' << ad[i].first << ' ' << ad[i].second << endl;
	return 0;
}