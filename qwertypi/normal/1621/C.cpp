#include <bits/stdc++.h>

using namespace std;

int timer = 0;
int qry(int x){
	cout << "? " << x << endl;
	int v;
	cin >> v;
	timer++;
	return v;
}

void ans(vector<int> vi){
	cout << "! ";
	for(auto i : vi){
		if(i != 0) cout << i << ' ';
	}
	cout << endl;
	return;
}

void sub(){
	int n;
	cin >> n;
	vector<int> p(n + 1);
	vector<vector<int>> P(n + 1);
	vector<int> _size(n + 1);
	map<int, pair<int, int>> M;
	for(int idx = 1; idx <= n; idx++){
		int res = qry(idx);
		if(M.find(res) != M.end()){
			pair<int, int> data = M[res];
			// cout << data.first << ' ' << data.second << endl;
			data.second = ((data.second - (timer - 1)) % _size[data.first] + _size[data.first]) % _size[data.first];
			P[data.first][data.second] = idx;
			// cout << "P" << ' ' << data.first << ' ' << data.second << ": " << idx << endl;
		}else{
			vector<int> cyc; // values
			int t = timer - 1;
			// cout << "timer: " << t << endl;
			cyc.push_back(res);
			while(cyc.size() <= 1 || cyc.front() != cyc.back()){
				cyc.push_back(qry(idx));
			}
			
			int m = cyc.size() - 1;
			int rt = cyc[(-t % m + m) % m];
			for(int i = 0; i < m; i++){
				M[cyc[i]] = {rt, (i + t) % m};
			}
			
			/*for(auto i : M){
				cout << i.first << " => " << i.second.first << ' ' << i.second.second << endl;
			}*/
			P[rt].resize(m);
			P[rt][0] = idx;
			//cout << "P " << rt << ' ' << t % m << ": " << idx << endl;
			_size[rt] = m;
		}
	}
	
	for(auto arr : P){
		if(arr.size()){
			for(int i = 0; i < (int) arr.size(); i++){
				p[arr[i]] = arr[(i + 1) % arr.size()];
			}
		}
	}
	ans(p);
}

int main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}