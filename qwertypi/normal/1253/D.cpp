#include <bits/stdc++.h>
using namespace std;

int Parent[200001];
int Bound[200001][2];
int Root(int x){
	while(x != Parent[x]){
		Parent[x] = Parent[Parent[x]];
		x = Parent[x];
	}
	return x;
}

bool Union(int x, int y){
	int root_x = Root(x);
	int root_y = Root(y);
	if(root_x == root_y){
		return false;
	}
	if(root_y > root_x){
		swap(root_x, root_y);
	}
	// So root_y < root_x
	Parent[root_x] = root_y;
	Bound[root_y][0] = min(Bound[root_x][0], Bound[root_y][0]);
	Bound[root_y][1] = max(Bound[root_x][1], Bound[root_y][1]);
	return true;
}

int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		Parent[i] = i;
		Bound[i][0] = Bound[i][1] = i;
	}
	for(int i = 0; i < m; i++){
		int v1, v2;
		cin >> v1 >> v2;
		Union(v1, v2);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(Parent[i] == i){
			for(int j = i; j <= Bound[i][1]; j++){
				ans += Union(i, j);
			}
			i = Bound[i][1];
		}
	}
	cout << ans << endl;
}