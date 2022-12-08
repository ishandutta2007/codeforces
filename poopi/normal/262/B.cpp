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

int n, k;
int arr[100010];

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    int p = 0;
    while(p < n && k && arr[p] < 0){
        arr[p++] *= -1;
        k--;
    }
    sort(arr, arr + n);
    if(k % 2)
        arr[0] *= -1;
    int res = 0;
    for(int i = 0; i < n; i++)
        res += arr[i];
    cout << res << endl;
    return 0;
}