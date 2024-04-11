#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> x_axis(1000);
vector<vector<int>> y_axis(1000);
vector<pair<int, int>> pts(100);
vector<vector<int>> graph(1000);
int visited[1000];
int ans = -1;
void dfs(int st){
	vector<int> stack{st};
	while(stack.size()){
		int v = stack.back();
		stack.pop_back();
		if(visited[v]){
			continue;
		}
		visited[v] = 1;
		for(auto i:graph[v]){
			stack.push_back(i);
		}
	}
	ans++;
}

int main(){
	fill(visited, visited + 1000, 0);
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		int x1, y1;
		cin >> x1 >> y1;
		x1--; y1--;
		x_axis[x1].push_back(i);
		y_axis[y1].push_back(i);
	}
	for(int i=0;i<1000;i++){
		if(x_axis[i].size() >= 2){
			for(int j=0;j<(int)x_axis[i].size()-1;j++){
				graph[x_axis[i][j]].push_back(x_axis[i][j+1]);
				graph[x_axis[i][j+1]].push_back(x_axis[i][j]);
			}
		}
		if(y_axis[i].size() >= 2){
			for(int j=0;j<(int)y_axis[i].size()-1;j++){
				graph[y_axis[i][j]].push_back(y_axis[i][j+1]);
				graph[y_axis[i][j+1]].push_back(y_axis[i][j]);
			}
		}
	}
	for(int i=0;i<n;i++){
		if(visited[i]){
			continue;
		}
		dfs(i);
	}
	cout << ans;
	return 0;
}