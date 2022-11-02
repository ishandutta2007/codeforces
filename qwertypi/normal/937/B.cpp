#include <bits/stdc++.h>
using namespace std;
 
bool check(int p, int y){
	if(y == 1) return false;
	for(int i = 2; i * i <= y; i++){
		if(y % i == 0){
			while(y % i == 0) y /= i;
			if(i <= p) return false;
		}
	}
	if(y != 1 && y <= p) return false;
	return true;
}
 
int main(){
	int p, y;
	cin >> p >> y;
	bool okay = false;
	while(!okay && y > p){
		okay |= check(p, y);
		if(!okay) y--;
	}
	cout << (y <= p ? -1 : y) << endl;
}