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

int n, k;
int arr[100010];
int cnt[100010];

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
	int len = -1, ans;
    int s = 0, e = 0, tot = 0;
    while(e < n){
        if(cnt[arr[e]] == 0)
            tot++;
        cnt[arr[e++]]++;
		while(cnt[arr[s]] > 1)
            cnt[arr[s++]]--;
		if(tot == k && (len == -1 || len > e - s)){
			len = e - s, ans = s;
			cnt[arr[s++]]--;
			tot--;
		}
    }
    if(len == -1)
        cout << "-1 -1" << endl;
    else cout << ans + 1 << ' ' << ans + len << endl;;
    return 0;
}