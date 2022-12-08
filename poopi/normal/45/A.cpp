				/* in the name of Allah */
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
using namespace std;

string mon[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

int main(){
	string inp;
	int n;
	while(cin >> inp >> n){
		int p = 0;
		while(mon[p] != inp)
			p++;
		cout << mon[(p + n) % 12] << endl;
	}
	return 0;
}