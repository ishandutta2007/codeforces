#include <bits/stdc++.h>
using namespace std;
  
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())  
typedef long double ld;
const int inf = 1e9 + 7;


int pow(int a, int b) {
	int res = 1;
	for(int i = 0;i < b;i++) res = res * a;
	return res;
}



signed main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
  	#endif
 
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
 

    int n;
    cin >> n;
    vector<int> min1(200001, inf), min2(200001, inf);
    vector<int> cnt(200001, 0);

   	for(int qq = 0;qq < n;qq++) {
   		int v;
   		cin >> v;
   		for(int j = 2;j * j <= v;j++) {
   			if (v % j != 0) continue;
   			cnt[j]++;
   			int c = 0;
   			while(v % j == 0) {
   				c++;
   				v /= j;
   			}
   			if (min1[j] > c) {
   				min2[j] = min1[j];
   				min1[j] = c;
   			}	else if (min2[j] > c) {
   				min2[j] = c;
   			}
   		}

   		if (v != 1) {
   			cnt[v]++;
   			min2[v] = min1[v];
   			min1[v] = 1;
   		}

   	}

   	for(int i = 0;i <= 200000;i++) {
   		if (cnt[i] <= n - 2) {
   			min1[i] = 0;
   			min2[i] = 0;
   		}else if (cnt[i] == n - 1) {
   			min2[i] = min1[i];
   			min1[i] = 0;
   		}
   	}

   	int res = 1;
   	for(int i = 2;i <= 200000;i++) res = res * pow(i, min2[i]);

   	cout << res;
}