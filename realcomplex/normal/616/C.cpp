#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair

const int N = 1005;
int cnt[N*N];
int cnf[N][N];
int p = 1;

void ini(){
	for(int i = 0;i<N;i++)
		for(int j = 0;j<N;j++)
			cnf[i][j] = -1;
}

int tt;
void dfs(int i , int j){
	tt++;
	cnf[i][j] = p;
	if(cnf[i+1][j]==INT_MAX)
		dfs(i+1,j);
	if(cnf[i-1][j]==INT_MAX)
		dfs(i-1,j);
	if(cnf[i][j+1]==INT_MAX)
		dfs(i,j+1);
	if(cnf[i][j-1]==INT_MAX)
		dfs(i,j-1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ini();
	int n,m;
	cin >> n >> m;
	char s;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			cin >> s;
			if(s=='.'){
				cnf[i][j] = INT_MAX;
			}
		}
	}
	p = 1;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			if(cnf[i][j] == INT_MAX){
				tt = 0;
				dfs(i,j);
				cnf[i][j]=p;
				cnt[p]=tt;
				p++;
			}
		}
	}
	int pr;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			if(cnf[i][j]!=-1){
				cout << ".";
				continue;
			}
			set<int>qi;
			if(cnf[i][j+1]!=-1)
				qi.insert(cnf[i][j+1]);
			if(cnf[i][j-1]!=-1)
				qi.insert(cnf[i][j-1]);
			if(cnf[i+1][j]!=-1)
				qi.insert(cnf[i+1][j]);
			if(cnf[i-1][j]!=-1)
				qi.insert(cnf[i-1][j]);
			pr = 1;
			for(auto x : qi)
				pr += cnt[x];
			pr%=10;
			cout << pr;
		}
		cout << "\n";
	}
	return 0;
}