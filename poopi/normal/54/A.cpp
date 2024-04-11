#include <iostream>
#include <string>

using namespace std;

int d[400];

int main(){
	int n, k, c;
	while(cin >> n >> k >> c){
		int cnt = 0;
		d[0] = 0;
		for(int i = 1; i <= c; i++){
			cin >> d[i];
			int dif = d[i] - d[i-1];
			cnt += (dif + k - 1) / k;
		}
		cnt += (n - d[c]) / k;
		cout << cnt << endl;
	}
	return 0;
}