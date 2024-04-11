#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
using namespace std;

vector<pair<int, int>> V(300000);
vector<map<int, int>> graph(300001);
int cnt[300001];
vector<int> major;
vector<int> minor;
int main(){
	fill(cnt, cnt + 300001, 0);
	int n, m;
	cin >> n >> m;
	for(int i=0;i<m;i++){
		int v1, v2;
		cin >> v1 >> v2;
		V.push_back(make_pair(v1, v2));
		cnt[v1]++;
		cnt[v2]++;
		if(graph[v1].find(v2) != graph[v1].end()){
			graph[v1][v2]++;
		}else{
			graph[v1][v2] = 1;
		}
		if(graph[v2].find(v1) != graph[v2].end()){
			graph[v2][v1]++;
		}else{
			graph[v2][v1] = 1;
		}
	}
	for(int i=1;i<=n;i++){
		if(cnt[i] >= (m + 1) / 2){
			major.push_back(i);
		}else{
			minor.push_back(i);
		}
	}
	for(int i=0;i<major.size();i++){
		for(int j=i+1;j<major.size();j++){
			int connected = cnt[major[i]] + cnt[major[j]] - graph[major[i]][major[j]];
			if(connected == m){
				cout << "YES";
				return 0;
			}
		}
	}
	for(int i=0;i<major.size();i++){
		for(int j=0;j<minor.size();j++){
			int connected = cnt[major[i]] + cnt[minor[j]] - graph[major[i]][minor[j]];
			if(connected == m){
				cout << "YES";
				return 0;
			}
		}
	}
	cout << "NO";
	return 0;
}