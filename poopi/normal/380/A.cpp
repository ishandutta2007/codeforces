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
#define Max 100000
#define Inf 1000000
#define Mod 1000000007LL

int n, q, m, pnt;
int64 arr[200010];
int64 v[100010][4];

void setV(int idx, int64 b, int64 c){
	v[idx][0] = (idx == 0 ? n : v[idx - 1][0] + v[idx - 1][3]);
	v[idx][1] = b;
	v[idx][2] = c;
	v[idx][3] = (c == -1 ? 1 : b * c);
}

int main(){
	cin >> q;
	int64 a, b, c;
	for(int i = 0; i < q; i++){
		cin >> a >> b;
		if(a == 2)
			cin >> c;
		else c = -1;
		if(n < Max){
			if(a == 1)
				arr[n++] = b;
			else{
				while(c > 0 && n < Max){
					for(int j = 0; j < b; j++)
						arr[n++] = arr[j];
					c--;
				}
				if(c > 0)
					setV(pnt++, b, c);
			}
		}
		else setV(pnt++, b, c);
	}
	cin >> m;
	int idx = 0;
	for(int i = 0; i < m; i++){
		cin >> a;
		a--;
		if(a < n)
			cout << arr[a];
		else{
			while(a >= v[idx][0] + v[idx][3])
				idx++;
			if(v[idx][2] == -1)
				cout << v[idx][1];
			else{
				a -= v[idx][0];
				a %= v[idx][1];
				cout << arr[a];
			}
		}

		if(i == m - 1)
			cout << endl;
		else cout << ' ';
	}
	return 0;
}