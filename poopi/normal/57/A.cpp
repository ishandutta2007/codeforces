							/* in the name of Allah */
#include <iostream>
#include <string>
#include <set>
using namespace std;

int main(){
	int T, n;
	int x1, y1, x2, y2;
	while(cin >> n){
		cin >> x1 >> y1 >> x2 >> y2;
		int d1 = x1 + y1, d2 = x2 + y2;
		int s1 = 0, s2 = 0;
		if(x1 == 0 || y1 == n)
			s1 = 1;
		if(x2 == 0 || y2 == n)
			s2 = 1;
		int dif = abs(s1 == s2 ? d1 - d2 : d1 + d2);
		if(dif > 2 * n)
			dif = 4 * n - dif;
		cout << dif << endl;
	}
	return 0;
}