							/* in the name of Allah */
#include <iostream>
#include <sstream>
#include <string>
#include <set>
using namespace std;

bool mark[1010];
string alch[11] = {"ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE", "TEQUILA", "VODKA", "WHISKEY", "WINE"};

int main(){
	int T, n;
	string inp;
	while(cin >> n){
		int cnt = 0;
		for(int i = 0; i < n; i++){
			cin >> inp;
			if(inp[0] >= '0' && inp[0] <= '9'){
				istringstream sin(inp);
				int a;
				sin >> a;
				if(a < 18)
					cnt++;
			}
			else{
				for(int i = 0; i < 11; i++)
					if(inp == alch[i])
						cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}