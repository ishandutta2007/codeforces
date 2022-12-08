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
#include <set>

using namespace std;

#define int64 long long
#define P pair<int, int>

int n, k;
int arr[100010];
set <int> st;

int main(){
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	for(int i = 0; i < n; i++){
		if(arr[i] % k != 0 || !st.count(arr[i] / k))
			st.insert(arr[i]);
	}
	cout << st.size() << endl;
	return 0;
}