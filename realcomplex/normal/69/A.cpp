#include <iostream>
using namespace std;

int main() {
	
	int n;
	cin >> n;
	int xs,ys,zs;
	xs = 0;
	ys = 0;
	zs = 0;
	int x,y,z;
	for(int i = 0;i<n;i++){
		cin >> x >> y >> z;
		xs += x;
		ys += y;
		zs += z;
	}
	if(xs == 0 && ys == 0 && zs == 0){
		cout << "YES";
	}
	else{
		cout << "NO";
	}
	return 0;
}