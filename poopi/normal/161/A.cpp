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

int n, m, x, y;
int a[100010];
int b[100010];
vector <int> u, v;

int main(){
	while(cin >> n >> m >> x >> y){
		for(int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		for(int i = 0; i < m; i++)
			scanf("%d", &b[i]);
		int p0 = 0, p1 = 0;
		while(p0 < n && p1 < m){
			if(b[p1] < a[p0] - x)
				p1++;
			else if(b[p1] > a[p0] + y)
				p0++;
			else{
				u.push_back(p0);
				v.push_back(p1);
				p0++, p1++;
			}
		}
		cout << u.size() << endl;
		for(int i = 0; i < u.size(); i++)
			printf("%d %d\n", u[i] + 1, v[i] + 1);
	}
	return 0;
}