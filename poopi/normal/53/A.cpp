							/* in the name of Allah */
#include <iostream>
#include <sstream>
#include <string>
#include <set>
using namespace std;

bool mark[1010];
string alch[11] = {"ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE", "TEQUILA", "VODKA", "WHISKEY", "WINE"};

int main(){
	int n;
	string inp, tmp, res;
	while(cin >> inp >> n){
		res = "";
		for(int i = 0; i < n; i++){
			cin >> tmp;
			if(tmp.length() >= inp.length() && tmp.substr(0, inp.length()) == inp)
				if(res == "" || res > tmp)
					res = tmp;
		}
		if(res == "")
			res = inp;
		cout << res << endl;
	}
	return 0;
}