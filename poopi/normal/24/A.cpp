						/* in the name of Allah */
#include <iostream>
#include <string>
using namespace std;

int n, sum, res;
int mat[110][110];
bool mark[110];

int dfs(int num){
	mark[num] = true;
	for(int i = 0; i < n; i++){
		if(!mark[i] && mat[num][i] != -1){
			res += mat[num][i];
			return dfs(i);
		}
	}
	return num;
}

int main(){
	cin >> n;
	int a, b, c;
	memset(mat, -1, sizeof mat);
	for(int i = 0; i < n; i++){
		cin >> a >> b >> c;
		a--, b--;
		mat[a][b] = 0;
		mat[b][a] = c;
		sum += c;
	}
	int tmp = dfs(0);
	res += mat[tmp][0];
	cout << min(res, sum - res) << endl;
	return 0;
}