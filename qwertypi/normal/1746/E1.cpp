#include <bits/stdc++.h>

using namespace std;

bool query(vector<int> v){
	cout << "? " << v.size() << ' ';
	for(auto i : v) cout << i << ' ';
	cout << endl;
	string b; cin >> b;
	return b == "YES";
}

bool query(vector<int> v1, vector<int> v2){
	vector<int> a;
	for(int i = 0; i < (v1.size() + 1) / 2; i++){
		a.push_back(v1[i]);
	}
	for(int i = 0; i < (v2.size() + 1) / 2; i++){
		a.push_back(v2[i]);
	}
	return query(a);
}

void answer(int x){
	cout << "! " << x << endl;
	string s; cin >> s;
	if(s == ":)") exit(0);
}

int main(){
	int n; cin >> n;
	set<int> ok, last;
	for(int i = 1; i <= n; i++){
		ok.insert(i); last.insert(i);
	}
	while(ok.size() > 2){
		vector<int> v1, v2;
		for(auto i : ok){
			if(last.count(i)){
				v2.push_back(i);
			}else{
				v1.push_back(i);
			}
		}
		if(v1.size() == 1){
			bool b = query(v1);
			if(b){
				last.clear();
				last.insert(v1[0]);
			}else{
				ok.erase(v1[0]);
			}
		}else{
			bool b = query(v1, v2);
			if(b){
				last.clear();
				for(int i = 0; i < (v1.size() + 1) / 2; i++){
					last.insert(v1[i]);
				}
				for(int i = 0; i < (v2.size() + 1) / 2; i++){
					last.insert(v2[i]);
				}
				
				for(int i = (v1.size() + 1) / 2; i < v1.size(); i++){
					ok.erase(v1[i]);
				}
			}else{
				last.clear();
				for(int i = (v1.size() + 1) / 2; i < v1.size(); i++){
					last.insert(v1[i]);
				}
				for(int i = (v2.size() + 1) / 2; i < v2.size(); i++){
					last.insert(v2[i]);
				}
				
				for(int i = 0; i < (v1.size() + 1) / 2; i++){
					ok.erase(v1[i]);
				}
			}
		}
	}
	answer(*ok.begin());
	answer(*--ok.end());
}