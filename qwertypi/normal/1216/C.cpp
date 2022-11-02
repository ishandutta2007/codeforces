#include <bits/stdc++.h>

using namespace std;

int x[6], y[6];

bool in(int id, double i, double j){
	return x[id * 2] <= i && i <= x[id * 2 + 1] && y[id * 2] <= j && j <= y[id * 2 + 1];
}

int main(){
	for(int i = 0; i < 6; i++){
		cin >> x[i] >> y[i];
	}
	bool done = false;
	for(auto i : {x[0], x[1]}) for(auto j : {y[0], y[1]})
		if(!done && !in(1, i, j) && !in(2, i, j)){
			cout << "YES" << endl;
			done = true;
		}
	if(x[3] + 1 <= x[4]){
		if(!done && (in(0, x[3] + 0.5, y[0]))){
			cout << "YES" << endl;
			done = true;
		}
	}
	if(x[5] + 1 <= x[2]){
		if(!done && (in(0, x[5] + 0.5, y[0]))){
			cout << "YES" << endl;
			done = true;
		}
	}
	if(y[3] + 1 <= y[4]){
		if(!done && (in(0, x[0], y[3] + 0.5))){
			cout << "YES" << endl;
			done = true;
		}
	}
	if(y[5] + 1 <= y[2]){
		if(!done && (in(0, x[0], y[5] + 0.5))){
			cout << "YES" << endl;
			done = true;
		}
	}
	if(!done) cout << "NO" << endl;
}