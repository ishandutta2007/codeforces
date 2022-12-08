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

int64 n, m, p;
int nz, tot;
int a[300000];
int b[300000];
int cnt[1000000];
map <int, int> mp;
vector <int> res;

int main(){
	cin >> n >> m >> p;
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		if(!mp.count(a[i]))
			mp[a[i]] = tot++;
		a[i] = mp[a[i]];
	}
	for(int i = 0; i < m; i++){
		scanf("%d", &b[i]);
		if(!mp.count(b[i]))
			mp[b[i]] = tot++;
		b[i] = mp[b[i]];
	}

	for(int s = 0; s < p; s++){
		if(s + (m - 1) * p >= n)
			continue;
		for(int i = 0; i < m; i++){
			if(cnt[b[i]] == 0)
				nz++;
			cnt[b[i]]--;
		}
		for(int i = 0; i < m; i++){
			if(cnt[a[s + i * p]] == 0)
				nz++;
			cnt[a[s + i * p]]++;
			if(cnt[a[s + i * p]] == 0)
				nz--;
		}
		if(nz == 0)
			res.push_back(s);

		int pnt = s;
		while(pnt + m * p < n){
			if(cnt[a[pnt]] == 0)
				nz++;
			cnt[a[pnt]]--;
			if(cnt[a[pnt]] == 0)
				nz--;

			if(cnt[a[pnt + m * p]] == 0)
				nz++;
			cnt[a[pnt + m * p]]++;
			if(cnt[a[pnt + m * p]] == 0)
				nz--;
			pnt += p;
			if(nz == 0)
				res.push_back(pnt);
		}

		for(int i = 0; i < m; i++){
			cnt[b[i]] = 0;
			cnt[a[pnt + i * p]] = 0;
		}
		nz = 0;
	}
	sort(res.begin(), res.end());
	cout << res.size() << endl;
	for(int i = 0; i < res.size(); i++)
		cout << res[i] + 1 << ' ';
	cout << endl;
	return 0;
}