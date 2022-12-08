							/* in the name of Allah */
#include <iostream>
#include <string>
#include <set>
using namespace std;

bool mark[1010];

int main(){
	int T, n;
	while(cin >> n){
		memset(mark, false, sizeof mark);
		int rem = n, p = 0;
		for(int i = 0; i <= 2 * n; i++){
			p = (p + i) % n;
			if(!mark[p])
				rem--;
			mark[p] = true;
		}
		cout << (rem ? "NO" : "YES") << endl;
	}
	return 0;
}