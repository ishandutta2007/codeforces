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

int n, m, k;
int r[1010], c[1010];
int mat[1010][1010];

int main(){
	string str;
	cin >> str;
	for(int i = 0; i < str.length(); i++)
		if(str[i] == '.')
			str[i] = ' ';
	istringstream sin(str);
	string a, b;
	sin >> a >> b;
	if(a[a.length() - 1] == '9')
		cout << "GOTO Vasilisa." << endl;
	else{
		if(b[0] >= '5')
			a[a.length() - 1]++;
		cout << a << endl;
	}
    return 0;
}