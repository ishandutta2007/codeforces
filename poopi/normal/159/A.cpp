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

ifstream fin("input.txt");
ofstream fout("output.txt");

#define uint unsigned int
#define int64 long long
#define P pair<int, int>
#define Pss pair<string, string>
#define PLL pair<int64, int64>
//#define cin fin
//#define cout fout

int n, d;
set <Pss> st;
string str[1010][2];
int tm[1010];

int main(){
	cin >> n >> d;
	for(int i = 0; i < n; i++){
		cin >> str[i][0] >> str[i][1] >> tm[i];
		for(int j = 0; j < i; j++)
			if(str[i][0] == str[j][1] && str[i][1] == str[j][0] && tm[i] != tm[j] && tm[i] - tm[j] <= d)
				st.insert(Pss(min(str[i][0], str[i][1]), max(str[i][0], str[i][1])));
	}
	cout << st.size() << endl;
	for(set <Pss>::iterator it = st.begin(); it != st.end(); it++)
		cout << (*it).first << ' ' << (*it).second << endl;
    return 0;
}