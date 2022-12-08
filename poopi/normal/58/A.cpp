							/* in the name of Allah */
#include <iostream>
#include <string>
#include <set>
using namespace std;

int main(){
	int T, n;
	string inp, hi = "hello";
	while(cin >> inp){
		int st = 0;
		for(int i = 0; i < inp.length() && st < 5; i++)
			if(inp[i] == hi[st])
				st++;
		cout << (st == 5 ? "YES" : "NO") << endl;
	}
	return 0;
}