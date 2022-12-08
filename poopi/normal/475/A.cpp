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
#define Pss pair<string, string>
#define PLL pair<int64, int64>
#define Inf 1000000
#define Mod 1000000007LL

string str[6];

int main(){
	str[0] = "+------------------------+";
	str[1] = "|#.#.#.#.#.#.#.#.#.#.#.|D|)";
	str[2] = "|#.#.#.#.#.#.#.#.#.#.#.|.|";
	str[3] = "|#.......................|";
	str[4] = "|#.#.#.#.#.#.#.#.#.#.#.|.|)";
	str[5] = "+------------------------+";
	int k, idx = 0;
	cin >> k;
	while(k){
		for(int i = 0; i < 6; i++){
			if(k && str[i][idx] == '#'){
				str[i][idx] = 'O';
				k--;
			}
		}
		idx++;
	}
	for(int i = 0; i < 6; i++)
		cout << str[i] << endl;
	return 0;
}