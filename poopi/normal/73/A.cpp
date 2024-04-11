							/* in the name of Allah */
#include <iostream>
#include <sstream>
#include <string>
#include <set>
using namespace std;

bool mark[1010];
string alch[11] = {"ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE", "TEQUILA", "VODKA", "WHISKEY", "WINE"};

int main(){
	int T, n, s[3], c[3];
	while(cin >> s[0] >> s[1] >> s[2] >> n){
		s[0]--, s[1]--, s[2]--;
		c[0] = c[1] = c[2] = 0;
		n = min(n, s[0] + s[1] + s[2]);
		int p = 0;
		for(int i = 0; i < n; ){
			if(c[p] < s[p]){
				c[p]++;
				i++;
			}
			p = (p + 1) % 3;
		}
		cout << (long long)(c[0] + 1) * (c[1] + 1) * (c[2] + 1) << endl;
	}
	return 0;
}