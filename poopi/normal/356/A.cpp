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

int n, m;
int b[300010];
set <int> st;

int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		st.insert(i);
	int l, r, w;
	for(int i = 0; i < m; i++){
		scanf("%d%d%d", &l, &r, &w);
		l--, r--, w--;
		while(!st.empty()){
			set<int>::iterator it = st.lower_bound(l);
			if(it == st.end()) break;
			int tmp = *it;
			if(tmp > r) break;
			st.erase(tmp);
			if(tmp != w)
				b[tmp] = w + 1;
		}
		st.insert(w);
	}
	for(int i = 0; i < n; i++)
		cout << b[i] << ' ';
	cout << endl;
	return 0;
}