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

int n, m, k;
int arr[100];

int main(){
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    reverse(arr, arr + n);
    int p = 0;
    while(p < n && k < m)
        k += arr[p++] - 1;
    if(k < m) cout << -1 << endl;
    else cout << p << endl;
    return 0;
}