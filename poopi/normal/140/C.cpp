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

int n, sum;
int arr[100010];
int rev[100010];
int out[100010];
map <int, int> mp;

int main(){
	while(cin >> sum){
		n = 0;
		mp.clear();
		int tmp;
		for(int i = 0; i < sum; i++){
			scanf("%d", &tmp);
			if(mp.count(tmp) == 0){
				arr[n] = 0;
				rev[n] = tmp;
				mp[tmp] = n++;
			}
			arr[mp[tmp]]++;
		}
		int l = 0, r = sum / 3;
		while(l < r){
			int mid = (l + r + 1) / 2;
			int cnt = 0;
			for(int i = 0; i < n; i++)
				cnt += min(mid, arr[i]);
			if(cnt >= 3 * mid)
				l = mid;
			else r = mid - 1;
		}
		cout << l << endl;
		int rem = 3 * l;
		for(int i = 0; i < n && rem > 0; i++){
			for(int j = 0; j < min(l, arr[i]) && rem > 0; j++){
				out[--rem] = rev[i];
				//cout << i << ' ' << min(l, arr[i]) << ' '
			}
		}
		sort(out, out + 3 * l);
		reverse(out, out + 3 * l);
		for(int i = 0; i < l; i++)
			cout << out[i] << ' ' << out[i + l] << ' ' << out[i + l + l] << endl;
	}
	return 0;
}