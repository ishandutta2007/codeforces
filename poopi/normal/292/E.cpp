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

int n, q, sz;
int a[100010];
int b[100010];
int ref[1000];

int get(int idx){
	int r = idx / sz;
	if(ref[r] == -1)
		return b[idx];
	return a[ref[r] + idx % sz];
}

int main(){
	memset(ref, -1, sizeof ref);
	cin >> n >> q;
	sz = sqrt((double)n) + 1;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < n; i++)
		cin >> b[i];
	int t, x, y, k;
	for(int I = 0; I < q; I++){
		cin >> t >> x;
		x--;
		if(t == 1){
			cin >> y >> k;
			y--;
			int r = y / sz;
			int c = y % sz;
			for(int i = 0; i < sz; i++)
				b[r * sz + i] = get(r * sz + i);
			ref[r] = -1;
			for(int i = c; k && i < sz; i++, k--)
				b[y++] = a[x++];

			while(k >= sz){
				ref[++r] = x;
				x += sz;
				y += sz;
				k -= sz;
			}

			r++;
			for(int i = 0; i < sz; i++)
				b[r * sz + i] = get(r * sz + i);
			ref[r] = -1;
			for(int i = 0; k && i < sz; i++, k--)
				b[y++] = a[x++];
		}
		else cout << get(x) << endl;
	}
	return 0;
}