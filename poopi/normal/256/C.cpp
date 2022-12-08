										/* in the name of Allah */
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

#define int64 long long
#define P pair<int, int>
#define Max 1000000
int n;
bool mark[10];
int gr[6] = {0, 1, 2, 0, 3, 1};
int arr[6][2] = {{1, 3}, {4, 15}, {16, 81}, {82, 6723}, {6724, 50625}, {50626, Max}};

int main(){
	cin >> n;
	int res = 0;
	int64 x;
	for(int I = 0; I < n; I++){
		cin >> x;
		if(x <= Max){
			for(int i = 0; i < 6; i++)
				if(arr[i][0] <= x && x <= arr[i][1])
					res ^= gr[i];
		}
		else{
			int mn = ceil(sqrt(sqrt((double)x))) + 1e-9;
			int mx = sqrt((double)x) + 1e-9;
			memset(mark, false, sizeof mark);
			for(int i = 0; i < 6; i++){
				if(mn <= arr[i][1] && mx >= arr[i][0])
					mark[gr[i]] = true;
			}
			int p = 0;
			while(mark[p]) p++;
			res ^= p;
		}
	}
	cout << (res ? "Furlo" : "Rublo") << endl;
	return 0;
}