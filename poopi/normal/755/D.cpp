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

int n, k;
int x[1000010];

struct fenwick_tree {
  fenwick_tree(){}
  int sum(int i, int j) {
    if (i == 0) {
      int S = 0;
      for (j; j >= 0; j = (j & (j + 1)) - 1) S += x[j];
      return S;
    } else return sum (0, j) - sum (0, i-1);
  }
  void add (int k, int a) {
    for (; k < n; k |= k+1) x[k] += a;
  }
}ft;


int main(){
	std::ios::sync_with_stdio(false);
	cin >> n >> k;
	k = min(k, n - k);
	int bef = 0;
	int64 ans = 1, cnt;
	for(int i = 0; i < n; i++){
		int cur = (bef + k) % n;
		if(bef < cur)
			cnt = ft.sum(bef + 1, cur - 1);
		else{
			cnt = 0;
			if(bef < n - 1)
				cnt += ft.sum(bef + 1, n - 1);
			if(cur > 0)
				cnt += ft.sum(0, cur - 1);
		}
		ans += cnt + 1;
		ft.add(bef, 1);
		ft.add(cur, 1);
		bef = cur;
		cout << ans << ' ';
	}
	cout << endl;
	return 0;
}