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

int n;
int arr[100010];
int cnt[100010];

int main(){
	while(cin >> n){
		int mn = 2000000000, mx = 1;
		for(int i = 0; i < n; i++){
			scanf("%d", &arr[i]);
			mn = min(mn, arr[i]);
			mx = max(mx, arr[i]);
		}
		int dif = mx - mn;
		if(n % 2 || dif > n / 2){
			cout << "NO" << endl;
			continue;
		}
		memset(cnt, 0, sizeof cnt);
		cnt[0] = 1;
		for(int i = 0; i < n; i++)
			cnt[arr[i] - mn]++;
		bool fl = true;
		/*cout << dif << endl;
		for(int j = 0; j <= dif; j++){
			cout << cnt[j] << ' ';
		}
		cout << endl;*/
		for(int i = dif; fl && i <= n / 2 && i > 0; i--){
			if(cnt[i] < cnt[i - 1]){
				n -= cnt[i] * 2;
				cnt[i - 1] -= cnt[i];
				cnt[i] = 0;
			}
			else fl = false;
			/*cout << fl << ' ' << i << ' ' << n << endl;
			for(int j = 0; j <= dif; j++){
				cout << cnt[j] << ' ';
			}
			cout << endl;*/
		}
		if(n != 0)
			fl = false;
		cout << (fl ? "YES" : "NO") << endl;
	}
	return 0;
}