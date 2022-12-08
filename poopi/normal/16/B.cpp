#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

#define P pair<int, int>

P arr[30];

int main(){
	int T, n, m;
	while(cin >> n >> m){
		for(int i = 0; i < m; i++)
			cin >> arr[i].second >> arr[i].first;
		sort(arr, arr + m);
		int p = m - 1;
		int res = 0;
		while(n && p >= 0){
			int t = min(n, arr[p].second);
			n -= t;
			res += t * arr[p--].first;
		}
		cout << res << endl;
	}
	return 0;
}