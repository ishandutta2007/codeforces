#include <iostream>
#include <vector>
#include <utility>
#include <deque>
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
#define fi first
#define se second
 
#define p 1000000007
 
using namespace std;
 
typedef long long ll;
 
vector<vector<int>> part(64);
vector<vector<int>> graph(100000);
struct data{
	int place, len, last;
	data(int _pl, int _le, int _la) : place(_pl), len(_le), last(_la){};
};
 
int dfs(int root){
	deque<data> stack = deque<data>{data{root, 0, -1}};
	bool temp = true;
	while(stack.size()){
		data elem = stack.back();
		stack.pop_back();
		if(elem.place == root && !temp){
			return elem.len;
			continue;
		}
		temp = false;
		for(auto i:graph[elem.place]){
			if(i == elem.last){
				continue;
			}
			stack.push_front(data {i, elem.len+1, elem.place});
		}
	}
	return -1;
}
 
int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		ll v;
		cin >> v;
		for(int j=0;j<64;j++){
			if(v % 2){
				part[j].pb(i);
			}
			v /= 2;
		}
	}
	for(int i=0;i<64;i++){
		if(part[i].size() >= 3){
			cout << 3;
			return 0;
		}
	}
	for(int i=0;i<64;i++){
		if(part[i].size() == 2){
			graph[part[i][0]].pb(part[i][1]);
			graph[part[i][1]].pb(part[i][0]);
		}
	}
	int ans = (1 << 30);
	for(int i=0;i<n;i++){
		if(graph[i].size() > 0){
			int res = dfs(i);
			if(res != -1){
				ans = min(res, ans);
			} 
		}
	}
	if(ans == (1 << 30)){
		cout << -1;
	}else{
		cout << ans;
	}
	return 0;
}