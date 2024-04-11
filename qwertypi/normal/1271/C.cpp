#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> st;
int main(){
	int n, s_x, s_y;
	cin >> n >> s_x >> s_y;
	int L = 0, R = 0, U = 0, D = 0;
	for(int i = 0; i < n; i++){
		int v1, v2;
		cin >> v1 >> v2;
		st.push_back({v1, v2});
		if(v1 < s_x){
			L++;
		}
		if(v1 > s_x){
			R++;
		}
		if(v2 > s_y){
			U++;
		}
		if(v2 < s_y){
			D++;
		}
	}
	if(L > R && L > U && L > D){
		cout << L << endl;
		cout << s_x - 1 << ' ' << s_y;
	}else if(R > U && R > D){
		cout << R << endl;
		cout << s_x + 1 << ' ' << s_y;
	}else if(U > D){
		cout << U << endl;
		cout << s_x << ' ' << s_y + 1;
	}else{
		cout << D << endl;
		cout << s_x << ' ' << s_y - 1;
	}
}