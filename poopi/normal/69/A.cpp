							/* in the name of Allah */
#include <iostream>
#include <string>
#include <set>
using namespace std;

int main(){
	int T, n;
	while(cin >> n){
		int sx = 0, sy = 0, sz = 0;
		int a, b, c;
		for(int i = 0; i < n; i++){
			cin >> a >> b >> c;
			sx += a, sy += b, sz += c;
		}
		cout << ((sx || sy || sz) ? "NO" : "YES") << endl;
	}
	return 0;
}