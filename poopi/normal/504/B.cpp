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
int x[200010];

struct fenwick_tree {
  fenwick_tree (){}
  int sum (int i, int j) {
    if (i == 0) {
      int S = 0;
      for (j; j >= 0; j = (j & (j + 1)) - 1) S += x[j];
      return S;
    } else return sum (0, j) - sum (0, i-1);
  }
  void add (int k, int a) {
    for (; k < n; k |= k+1) x[k] += a;
  }
} ft;

int cnt[200010];
int res[200010];
int arr[200010];

void calc(){
	memset(x, 0, sizeof x);
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	for(int i = n - 1; i >= 0; i--){
		cnt[n - 1 - i] += ft.sum(0, arr[i]);
		ft.add(arr[i], 1);
	}
}

int main(){
	cin >> n;
	calc();
	calc();

	for(int i = 0; i < n; i++){
		if(cnt[i] >= i + 1){
			cnt[i] -= i + 1;
			cnt[i + 1]++;
		}
	}

	memset(x, 0, sizeof x);
	for(int i = n - 1; i >= 0; i--){
		int l = 0, r = n - 1;
		while(l < r){
			int mid = (l + r) / 2;
			if(mid - ft.sum(0, mid) >= cnt[i])
				r = mid;
			else l = mid + 1;
		}
		res[n - i - 1] = r;
		ft.add(r, 1);
	}

	for(int i = 0; i < n; i++)
		cout << res[i] << ' ';
	cout << endl;
	return 0;
}