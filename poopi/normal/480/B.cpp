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

int n, l, x, y;
int arr[100010];
set <int> st;
bool hx, hy, hd, hs;

int main(){
	cin >> n >> l >> x >> y;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		st.insert(arr[i]);
	}
	int ans;
	for(int i = 0; i < n; i++){
		if(st.count(arr[i] + x))
			hx = true;
		if(st.count(arr[i] + y))
			hy = true;
		if(st.count(arr[i] + y + x)){
			hs = true;
			ans = arr[i] + x;
		}
		if(st.count(arr[i] + y - x) && arr[i] >= x){
			hd = true;
			ans = arr[i] - x;
		}
		if(st.count(arr[i] + y - x) && arr[i] <= l - y){
			hd = true;
			ans = arr[i] + y;
		}
	}
	if(hx && hy)
		cout << 0 << endl;
	else if(hx || hy){
		cout << 1 << endl;
		cout << (hx ? y : x) << endl;
	}
	else if(hs || hd){
		cout << 1 << endl;
		cout << ans << endl;
	}
	else{
		cout << 2 << endl;
		cout << x << ' ' << y << endl;
	}
	return 0;
}