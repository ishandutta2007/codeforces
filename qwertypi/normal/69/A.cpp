#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int cnt[5];
int main(){
	int v[3] = {0, 0, 0};
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		int v1[3];
		cin >> v1[0] >> v1[1] >> v1[2];
		v[0] += v1[0];
		v[1] += v1[1];
		v[2] += v1[2];
	}
	if(v[0] == 0 && v[1] == 0 && v[2] == 0){
		cout << "YES";
	}else{
		cout << "NO";
	}
	return 0;
}