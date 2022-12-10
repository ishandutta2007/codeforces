#include <bits/stdc++.h>

using namespace std;

char c[10][10];
int ans1 = 100, ans2 = 100;

int main(){
	for(int i = 0; i < 8; i++){
		cin >> c[i];
		for(int j = 0; j < 8; j++){
			if(c[i][j] == 'W'){
				int cnt = 0;
				for(int i2 = i - 1; i2 >= 0; i2--)
					if(c[i2][j] == 'B')
						cnt = 1000;
					else
						cnt++;
				ans1 = min(ans1, cnt);
			}
		}
	}
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			if(c[i][j] == 'B'){
				int cnt = 0;
				for(int i2 = i + 1; i2 < 8; i2++)
					if(c[i2][j] == 'W')
						cnt = 1000;
					else
						cnt++;
				ans2 = min(ans2, cnt);
			}
		}
	}
	cout << (ans1 <= ans2 ? "A" : "B") << endl;
}