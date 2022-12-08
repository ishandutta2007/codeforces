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

struct tri {
	int64 mx, left, right;
	tri(int64 m = 0, int64 l = 0, int64 r = 0){
		mx = m, left = l, right = r;
	}
};

int n, m;
int64 d[100010];
int64 h[100010];
int64 sum[100010];
tri val[500010];

tri init(int idx, int str, int end){
	if(str == end)
		return val[idx] = tri(0, h[str], h[str]);

	int mid = (str + end) / 2;
	tri t1 = init(2 * idx + 1, str, mid);
	tri t2 = init(2 * idx + 2, mid + 1, end);

	val[idx].mx = max(max(t1.mx, t2.mx), t1.right + t2.left + d[mid]);
	val[idx].left = max(t1.left, t2.left + sum[mid + 1] - sum[str]);
	val[idx].right = max(t1.right + sum[end] - sum[mid], t2.right);
	return val[idx];
}

tri query(int idx, int str, int end, int l, int r){
	if(l <= str && end <= r)
		return val[idx];

	int mid = (str + end) / 2;
	if(r < mid + 1)
		return query(2 * idx + 1, str, mid, l, r);
	if(mid < l)
		return query(2 * idx + 2, mid + 1, end, l, r);

	tri t1 = query(2 * idx + 1, str, mid, l, r);
	tri t2 = query(2 * idx + 2, mid + 1, end, l, r);

	tri ret;
	ret.mx = max(max(t1.mx, t2.mx), t1.right + t2.left + d[mid]);
	ret.left = max(t1.left, t2.left + sum[mid + 1] - sum[str]);
	ret.right = max(t1.right + sum[end] - sum[mid], t2.right);
	return ret;
}

int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> d[i];
	for(int i = 0; i < n; i++){
		cin >> h[i];
		h[i] *= 2;
	}
	sum[0] = 0;
	for(int i = 1; i < n; i++)
		sum[i] = sum[i - 1] + d[i - 1];

	init(0, 0, n - 1);
	int a, b;
	for(int i = 0; i < m; i++){
		cin >> a >> b;
		a--, b--;
		if(a <= b){
			int64 res;
			if(b == n - 1)
				res = query(0, 0, n - 1, 0, a - 1).mx;
			else if(a == 0)
				res = query(0, 0, n - 1, b + 1, n - 1).mx;
			else{
				tri t1 = query(0, 0, n - 1, 0, a - 1);
				tri t2 = query(0, 0, n - 1, b + 1, n - 1);
				res = max(t1.mx, t2.mx);
				res = max(res, t2.right + d[n - 1] + t1.left);
			}
			cout << res << endl;
		}
		else{
			tri t = query(0, 0, n - 1, b + 1, a - 1);
			cout << t.mx << endl;
		}
	}
	return 0;
}