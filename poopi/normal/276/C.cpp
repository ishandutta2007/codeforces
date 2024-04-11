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
#define PLL pair<int64, int64>

int n, q;
int64 arr[200010];
int64 cnt[200010];
priority_queue <int> s, e;

int main(){
	cin >> n >> q;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	int a, b;
	for(int i = 0; i < q; i++){
		cin >> a >> b;
		s.push(-a + 1);
		e.push(-b + 1);
	}
	int tot = 0;
	for(int i = 0; i < n; i++){
		while(!s.empty() && s.top() == -i){
			tot++;
			s.pop();
		}
		cnt[i] = tot;
		while(!e.empty() && e.top() == -i){
			tot--;
			e.pop();
		}
	}
	sort(cnt, cnt + n);
	int64 res = 0;
	for(int i = 0; i < n; i++)
		res += cnt[i] * arr[i];
	cout << res << endl;
    return 0;
}