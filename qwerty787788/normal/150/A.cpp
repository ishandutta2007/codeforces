#include <iostream>
#include <cstring>
#include <vector>
#include <cctype> 
#include <cstdio>
#include <string>
#include <cmath>
#include <ctime>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
//
ll x;
vector <ll> del;
//
//
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//
	cin >> x;
	if (x < 4) {
		cout << "1" << endl << "0" << endl;
		return 0;
	}
	for (ll i = 2; i*i <= x; i++) 
		if (x % i == 0) {
			del.push_back(i);
			if (del.size() == 2) {
				if (del[1] % del[0] == 0) {
					cout << 1 <<  endl << del[1] << endl;
				} else {
					cout << 1 <<  endl << del[1]*del[0] << endl;
				}
				return 0;
			}
		}
	if (del.size() == 1 && del[0]*del[0] != x) {
		if ((x / del[0])% del[0] == 0) {
			cout << 1 << endl << (x/del[0]) << endl;
			return 0;
		}
	}
	if (del.size() == 0) {
		cout << 1 << endl << 0 << endl;
		return 0;
	}
	cout << 2;
	//	
}