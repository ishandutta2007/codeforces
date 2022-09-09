#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <set>
//#include <cmath>
using namespace std;
#define PI 3.1415926535897932384626433832795
//
long long a, b, mod, x;
long long start;
//
int main() {
	//freopen("input.txt", "r", stdin);
	//
	cin >> a >> b >> mod;
	if (b >= mod) {
		cout << "2" << endl;
	} else {
		x  = 1;
		long long answ = -1;
		bool  quit = false;
		long long new1 = (x*1000000000)%mod;
		long long new2 = new1;
		if ((new2>0)&&(new2<mod-b)&&(x<=a)) answ = x;
		start = new1;
		while ((answ == -1)&&(x<a)&&((x == 1)||((start != new2)&&(!((new2>0)&&(new2<mod-b)))))) {
			x++;
			new2 = (new2+new1)%mod;
			if ((new2>0)&&(new2<mod-b)) answ = x;
		}
		if (answ == -1){
			cout << "2" << endl;}
		else {
			int x1 = 0;
			long long answ2= answ;
			while (answ != 0) {
				x1 ++;
				answ = answ/10;
			}
			cout << "1 ";
			x1 = 9 - x1;
			for (int i = 0; i < x1; i++) cout << "0";
			cout << answ2 << endl;
		}
					
	}
	//
	return 0;
}