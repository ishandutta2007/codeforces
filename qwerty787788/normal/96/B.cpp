#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cmath>
using namespace std;
#define PI 3.1415926535897932384626433832795
//
long long result;
int N;
//
void add(long long x, int d) {
	if (x < result) {
		if ((x>=N)&&(d==0)) 
			result = x;
		else {
			add(x*10+4, d+1);
			add(x*10+7, d-1);
		}
	}
}
//
int main() {
	//cout.precision(1);
	//freopen("input.txt", "r", stdin);
	
	cin >> N;
	result = 200000000000;
	add(4, 1);
	add(7, -1);
	cout << result << endl;
	//

	//
	return 0;
}