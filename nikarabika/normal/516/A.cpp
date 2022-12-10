#include <bits/stdc++.h>

using namespace std;

bool x[10] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0};
int p[10];

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		char c;
		cin >> c;
		c = c - '0';
		for(int j = 2; j <= c; j++){
		int x = j, div = 2;
		while(x > 1){
			while(x % div == 0){
				p[div]++;
				x /= div;
			}
			div++;
		}
		}
	}
	vector<int> ans;
	for(int i = 9; i > 0; i--) if(x[i]){
		while(p[i] > 0){
			ans.push_back(i);
			for(int j = 2; j <= i; j++){
				int x = j, div = 2;
				while(x > 1){
					while(x % div == 0){
						p[div] --;
						x /= div;
					}
					div ++;
				}
			}
		}
	}
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i];
	cout << endl;
	return 0;
}