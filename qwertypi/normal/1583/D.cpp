#include <bits/stdc++.h>

using namespace std;
// lol much overrated
int query(vector<int> a){
	cout << "? ";
	for(auto i : a){
		cout << i << ' '; 
	}
	cout << endl;
	int ver; cin >> ver;
	return ver;
}

int ans[101];
int main(){
	int n;
	cin >> n;
	int la = n;
	for(int i = 2; i <= n; i++){
		vector<int> v;
		for(int j = 0; j < n - 1; j++) v.push_back(i);
		v.push_back(1);
		int r = query(v);
		if(!r){
			la = i - 1;
			break;
		}
	}
	ans[n - 1] = la;
	for(int i = 1; i <= n; i++){
		if(i == la) continue;
		vector<int> v;
		if(la > i){
			for(int j = 0; j < n - 1; j++) v.push_back(la - i + 1);
			v.push_back(1);
		}else{
			for(int j = 0; j < n - 1; j++) v.push_back(n + la - i);
			v.push_back(n);
		}
		int ret = query(v);
		ans[ret - 1] = i;
	}
	cout << "! "; 
	for(int i = 0; i < n; i++){
		cout << ans[i] << ' ';
	}
	cout << endl; 
}