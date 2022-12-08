							/* in the name of Allah */
#include <iostream>
#include <string>
using namespace std;

int n, m;

int main(){
	cin >> n >> m;
	string s1, s2, s3, s4;
	int tmp, mn = 0, mx = n + 1;
	for(int i = 0; i < m; i++){
		cin >> s1 >> s2 >> s3 >> s4 >> tmp;
		if(s3[0] == 'r')
			mn = max(mn, tmp);
		else mx = min(mx, tmp);
	}
	int res = mx - mn - 1;
	cout << (res > 0 ? res : -1) << endl;
	return 0;
}