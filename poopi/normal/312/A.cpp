                                       /* in the name of Allah */

#include <algorithm>
#include <iostream>
#include <memory.h>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <list>
#include <map>
#include <set>

using namespace std;

#define uint unsigned int
#define int64 long long
#define P pair<int, int>
#define PLL pair<int64, int64>

int64 cnt, res;

int main(){
	int k;
	string str;
	cin >> k;
	getline(cin, str);
	for(int i = 0; i < k; i++){
		getline(cin, str);
		bool f = (str.length() >= 5 && str.substr(0, 5) == "miao.");
		bool s = (str.length() >= 5 && str.substr(str.length() - 5) == "lala.");
		if(f && !s)
			cout << "Rainbow's" << endl;
		else if(!f && s)
			cout << "Freda's" << endl;
		else cout << "OMG>.< I don't know!" << endl;
	}
    return 0;
}