#include <iostream>
#include <algorithm>
using namespace std;

int prec[200001][2];

int ans[2];
int n;

bool f(int len){
	for(int i=0;i<n+1-len;i++){
		int x = prec[n][0] - (prec[i+len][0] - prec[i][0]);
		int y = prec[n][1] - (prec[i+len][1] - prec[i][1]);
		int d1 = ans[0] - x;
		int d2 = ans[1] - y;
		if(abs(d1) + abs(d2) <= len){
			return true;
		}
	}
	return false;
}
int main(){
	string s;
	cin >> n >> s;
	int x, y;
	cin >> x >> y;
	ans[0] = x;
	ans[1] = y;
	if(abs(x) + abs(y) > n || abs(x + y - n) % 2 == 1){
		cout << -1 << endl;
		return 0;
	}
	prec[0][0] = 0;
	prec[0][1] = 0;
	for(int i=0;i<n;i++){
		switch(s[i]){
			case 'R':
				prec[i+1][0] = prec[i][0] + 1;
				prec[i+1][1] = prec[i][1];
				break;
			case 'L':
				prec[i+1][0] = prec[i][0] - 1;
				prec[i+1][1] = prec[i][1];
				break;
			case 'U':
				prec[i+1][0] = prec[i][0];
				prec[i+1][1] = prec[i][1] + 1;
				break;
			case 'D':
				prec[i+1][0] = prec[i][0];
				prec[i+1][1] = prec[i][1] - 1;
				break;
		}
	}
	int upper = n;
	int lower = 0;
	while(lower != upper){
		int mid = (upper + lower) / 2;
		if(f(mid)){
			upper = mid;
		}else{
			lower = mid + 1;
		}
	}
	cout << lower << endl;
	return 0;
}