#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct K{
	int id, x, y, z;
	K(int _id, int _x, int _y, int _z) : x(_x), y(_y), z(_z), id(_id){};
	K(){};
};
vector<K> A;

map<int, vector<K>> x_map;
map<int, vector<K>> y_map;
map<int, K> z_map;
vector<pair<int, int>> ans_x;
vector<pair<int, int>> ans_y;
vector<pair<int, int>> ans_z;
bool used[50000];
void g(vector<K> C){
	z_map.clear();
	for(auto i : C){
		z_map[i.z] = i;
	}
	K data(-1, 0, 0, 0);
	for(auto j : z_map){
		auto i = j.second;
		if(data.id != -1){
			ans_z.push_back({data.id + 1, i.id + 1});
			used[data.id] = used[i.id] = 1;
			data.id = -1;
		}else{
			data.id = i.id;
		}
	}
}

void f(vector<K> B){
	y_map.clear();
	for(auto i : B){
		y_map[i.y].push_back(i);
	}
	for(auto i : y_map){
		g(i.second);
	}
	K data(-1, 0, 0, 0);
	for(auto j : y_map){
		auto i = j.second;
		if(i.size()){
			for(auto k : i){
				if(!used[k.id]){
					if(data.id != -1){
						ans_y.push_back({data.id + 1, k.id + 1});
						used[data.id] = used[k.id] = 1;
						data.id = -1;
					}else{
						data.id = k.id;
					}
				}
			}
		}
	}
}

int main(){
	fill(used, used + 50000, 0);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		int x, y, z;
		cin >> x >> y >> z;
		A.push_back(K(i, x, y, z));
		x_map[A[i].x].push_back(A[i]);
	}
	for(auto i : x_map){
		f(i.second);
	}
	K data(-1, 0, 0, 0);
	for(auto j : x_map){
		auto i = j.second;
		if(i.size()){
			for(auto k : i){
				if(!used[k.id]){
					if(data.id != -1){
						ans_x.push_back({data.id + 1, k.id + 1});
						used[data.id] = used[k.id] = 1;
						data.id = -1;
					}else{
						data.id = k.id;
					}
				}
			}
		}
	}
	for(auto i : ans_z){
		cout << i.first << ' ' << i.second << endl;
	}
	for(auto i : ans_y){
		cout << i.first << ' ' << i.second << endl;
	}
	for(auto i : ans_x){
		cout << i.first << ' ' << i.second << endl;
	}
	return 0;
}