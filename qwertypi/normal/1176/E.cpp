#include <iostream>
#include <vector>
#include <utility>
using namespace std;

vector<vector<int>> graph(200001);
bool visited[200001];
void dfs(int n, int m){
	/*for(int i=1;i<=n;i++){
		cout << i << ": ";
		for(auto j:graph[i]){
			cout << j << ' ';
		}
		cout << endl;
	}*/
	fill(visited+1, visited+n+1, 0);
	vector<int> red;
	vector<int> black;
	vector<pair<int, bool>> stack{pair<int, bool>{1, false}};
	while(stack.size()){
		pair<int, bool> vertex = stack.back();
		stack.pop_back();
		if(visited[vertex.first]){
			continue;
		}
		if(vertex.second){
			red.push_back(vertex.first);
		}else{
			black.push_back(vertex.first);
		}
		visited[vertex.first] = true;
		for(auto i:graph[vertex.first]){
			bool state = 1 ^ vertex.second;
			stack.push_back(pair<int, bool>{i, state});
		}
	}
	if(red.size() <= black.size()){
		cout << red.size() << endl;
		for(auto i:red){
			cout << i << ' ';
		}
		cout << endl;
	}else{
		cout << black.size() << endl;
		for(auto i:black){
			cout << i << ' ';
		}
		cout << endl;
	}
}

int main(){
	int t;
	cin >> t;
	for(int i=0;i<t;i++){
		int n, m;
		cin >> n >> m;
		for(int i=1;i<=n;i++){
			graph[i].clear();
		}
		for(int j=0;j<m;j++){
			int v1, v2;
			cin >> v1 >> v2;
			graph[v1].push_back(v2);
			graph[v2].push_back(v1);
		}
		dfs(n, m);
	}
}