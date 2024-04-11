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

int n;
int a[2010], b[2010];
int pr[2010], rev[2010];
vector <P> ans;

int main(){
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < n; i++){
		cin >> b[i];
		rev[b[i]] = i;
	}
	for(int i = 0; i < n; i++)
		pr[i] = rev[a[i]];

	int sum = 0;
	for(int i = 0; i < n; i++){
		vector <int> v;
		int t = pr[i];
		while(t < i){
			v.push_back(t);
			t = pr[t];
		}
		int cur = i;
		for(int j = (int)v.size() - 1; j >= 0; j--){//signed int!
			swap(pr[cur], pr[v[j]]);
			ans.push_back(P(cur + 1, v[j] + 1));
			sum += cur - v[j];
			cur = v[j];
		}
	}
	cout << sum << endl << ans.size() << endl;
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i].first << ' ' << ans[i].second << endl;
	return 0;
}