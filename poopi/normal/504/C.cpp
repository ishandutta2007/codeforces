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
int arr[100010];
int cnt[100010];

int64 calc(){
	memset(cnt, 0, sizeof cnt);
	for(int i = 0; i < n; i++)
		cnt[arr[i]]++;

	int64 res = 0;
	for(int i = 0; i < n; i++, res++){
		if(i < n / 2){
			if(cnt[arr[i]] > 1)
				cnt[arr[i]] -= 2;
			else break;
		}
		else if(n % 2 && i == n / 2){
			if(cnt[arr[i]] % 2)
				cnt[arr[i]]--;
			else break;
		}
		else if(arr[i] != arr[n - i - 1])
				break;
	}
	return res;
}

int main(){
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> arr[i];

	for(int i = 0; i < n; i++)
		cnt[arr[i]]++;
	int odd = 0;
	for(int i = 1; i <= n; i++)
		if(cnt[i] % 2)
			odd++;
	if(odd > 1){
		cout << 0 << endl;
		return 0;
	}

	int64 eq = 0;
	for(int i = 0; i < n; i++){
		if(arr[i] != arr[n - i - 1])
			break;
		eq++;
	}
	if(eq == n){
		cout << eq * (eq + 1) / 2 << endl;
		return 0;
	}
	n -= 2 * eq;	
	for(int i = 0; i < n; i++)
		arr[i] = arr[i + eq];

	int64 res = calc();
	reverse(arr, arr + n);
	res += calc();
	cout << res * (eq + 1) + (eq + 1) * (eq + 1) << endl;
	return 0;
}