							/* in the name of Allah */
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int d, m, y;
int sz[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool poss(int a, int b, int c){
	if(b < 1 || b > 12)
		return false;
	int dd;
	if(c % 4 == 0 && b == 2)
		dd = 29;
	else dd = sz[b-1];
	if(a < 1 || a > dd)
		return false;
	if(y - c != 18)
		return y - c > 18;
	if(b != m)
		return m > b;
	return d >= a;
}

int main(){
	string str;
	cin >> str;
	for(int i = 0; i < str.length(); i++)
		if(str[i] == '.')
			str[i] = ' ';
	istringstream sin(str);
	sin >> d >> m >> y;
	int t[3], a[3] = {0, 1, 2};
	cin >> str;
	for(int i = 0; i < str.length(); i++)
		if(str[i] == '.')
			str[i] = ' ';
	istringstream sin2(str);
	sin2 >> t[0] >> t[1] >> t[2];
	bool can = false;
	do{
		if(poss(t[a[0]], t[a[1]], t[a[2]])){
			cout << "YES" << endl;
			can = true;
			break;
		}
	}
	while(next_permutation(a, a + 3));
	if(!can)
		cout << "NO" << endl;
	return 0;
}