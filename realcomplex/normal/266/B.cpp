#include <bits/stdc++.h>

using namespace std;

int main() {
	
	int n;
	cin >> n >> n;
	string sk;
	cin >> sk;
	char re;
	for(int i = 0;i<n;i++){
		for(int x = 1;x<sk.size();x++){
			if(sk[x] == 'G' && sk[x - 1] == 'B'){
				re = sk[x];
				sk[x] = sk[x - 1];
				sk[x - 1] = re;
				x++;
			}
		}
	}
	cout << sk;
	return 0;
}