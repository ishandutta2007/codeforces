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

int n;
string name[110];
int cnt[110][3];
int mx[3];

int main(){
	cin >> n;
	int k;
	for(int i = 0; i < n; i++){
		cin >> k >> name[i];
		string str;
		for(int j = 0; j < k; j++){
			cin >> str;
			str = str.substr(0, 2) + str.substr(3, 2) + str.substr(6, 2);
			bool f1 = true, f2 = true;
			for(int a = 0; a < 5; a++){
				if(str[a] != str[a + 1])
					f1 = false;
				if(str[a] <= str[a + 1])
					f2 = false;
			}
			if(f1) cnt[i][0]++;
			else if(f2) cnt[i][1]++;
			else cnt[i][2]++;
		}
		for(int j = 0; j < 3; j++)
			mx[j] = max(mx[j], cnt[i][j]);
	}
	bool fir = true;
	cout << "If you want to call a taxi, you should call: ";
	for(int i = 0; i < n; i++){
		if(cnt[i][0] == mx[0]){
			if(!fir)
				cout << ", ";
			fir = false;
			cout << name[i];
		}
	}
	cout << '.' << endl;
	fir = true;
	cout << "If you want to order a pizza, you should call: ";
	for(int i = 0; i < n; i++){
		if(cnt[i][1] == mx[1]){
			if(!fir)
				cout << ", ";
			fir = false;
			cout << name[i];
		}
	}
	cout << '.' << endl;
	fir = true;
	cout << "If you want to go to a cafe with a wonderful girl, you should call: ";
	for(int i = 0; i < n; i++){
		if(cnt[i][2] == mx[2]){
			if(!fir)
				cout << ", ";
			fir = false;
			cout << name[i];
		}
	}
	cout << '.' << endl;
	return 0;
}