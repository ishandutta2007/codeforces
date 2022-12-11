#include <iostream>
#include <string.h>

#define N 5010

using namespace std;

int opt[2][N];
string str;
int n,m;

int main() {
	int i,j;
	cin >> str;
	int l = str.length();
	int ans = 0;
	for(i=l-1;i>=0;i--) {
		int k = i%2;
		for(j=i;j<l;j++) {
			if(j-i < 3)
				opt[k][j] = 0;
			else if(j-i == 3) {
				opt[k][j] = (str.substr(i,4) == "bear");
			}else {
				opt[k][j] = opt[!k][j];
				if(j > 0)
					opt[k][j] = opt[!k][j] || opt[k][j-1];
			}
			ans += opt[k][j];
		}
	}
	cout << ans << endl;
	return 0;
}