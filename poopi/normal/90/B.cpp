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
#define Inf 1000000
#define Mod 1000000007LL
//#define cin fin
//#define cout fout

int r, c;
string str[110];
bool mark[110][110];

int main(){
	cin >> r >> c;
	for(int i = 0; i < r; i++)
		cin >> str[i];
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			for(int k = 0; k < r; k++)
				if(k != i && str[i][j] == str[k][j])
					mark[i][j] = true;
			for(int k = 0; k < c; k++)
				if(k != j && str[i][j] == str[i][k])
					mark[i][j] = true;
		}
	}
	for(int i = 0; i < r; i++)
		for(int j = 0; j < c; j++)
			if(!mark[i][j])
				cout << str[i][j];
	cout << endl;
}