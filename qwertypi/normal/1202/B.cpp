#include <iostream>
#include <string>
#define inf (1LL << 30)
typedef long long ll;
using namespace std;
ll dp[10][10][10]; // m1, m2, res
ll ans[10][10];
int main(){
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			for(int k=0;k<10;k++){
				dp[i][j][k] = inf;
			}
			ans[i][j] = 0;
		}
	}
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			for(int x=0;x<10;x++){
				for(int y=0;y<10;y++){
					if(x + y == 0){
						continue;
					}
					dp[i][j][(x * i + y * j) % 10] = min(dp[i][j][(x * i + y * j) % 10], (ll)x + y - 1);
				}
			}
		}
	}
	string s;
	cin >> s;
	char curInt = s[0];
	for(int i=1;i<s.size();i++){
		for(int j=0;j<10;j++){
			for(int k=0;k<10;k++){
				ans[j][k] = min(ans[j][k] + dp[j][k][(s[i] - curInt + 10) % 10], inf);
			}
		}
		curInt = s[i];
	}
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			cout << (ans[i][j] == inf ? -1 : ans[i][j]) << ' ';
		}
		cout << endl;
	}
}