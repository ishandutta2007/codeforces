								/* in the name of Allah */
#include <iostream>
#include <algorithm>
using namespace std;

#define int64 long long
#define Inf 1000000LL

int n, k;
int64 a[100010][26], b[100010][26];
char c[100010];
char s[100010];

int main(){
	cin >> n >> k;
	scanf("%s", c);
	int len = strlen(c);
	for(int i = 0; i < 26; i++)
		b[len-1][i] = a[0][i] = Inf;
	a[0][c[0] - 'a'] = 0;
	b[len-1][c[len - 1] - 'a'] = 0;
	for(int i = 1; i < len; i++){
		for(int j = 0; j < 26; j++)
			a[i][j] = min(Inf, a[i-1][j] + 1);
		a[i][c[i] - 'a'] = 0;
	}
	for(int i = len - 2; i >= 0; i--){
		for(int j = 0; j < 26; j++)
			b[i][j] = min(Inf, b[i+1][j] + 1);
		b[i][c[i] - 'a'] = 0;
	}
	for(int i = 0; i < n; i++){
		int64 res = 0;
		scanf("%s", s);
		int m = strlen(s);
		for(int jj = 0; jj < m; jj++){
			int j = min(jj, len - 1);
			int64 tmp = min(a[j][s[jj] - 'a'], b[j][s[jj] - 'a']);
			if(jj > len - 1){
				tmp += jj - len + 1;
			}
			//cout << tmp << ' ';
			if(tmp >= Inf)
				tmp = m;
			//cout << j << ' ' << tmp << endl;
			res += tmp;
		}
		//cout << endl;
		cout << res << endl;
	}
	//cin >> n;
	return 0;
}