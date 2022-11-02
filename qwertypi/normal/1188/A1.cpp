#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> graph(100001);

int main(){
	int n;
	cin >> n;
	for(int i=0;i<n-1;i++){
		int v1, v2;
		cin >> v1 >> v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}
	for(int i=1;i<=n;i++){
		if(graph[i].size() == 2){
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}