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

int n, m;
int arr[100010];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int mx = 1;
    for(int i = 0; i < n; i++){
        int s = i, e = i;
        while(s > 0 && arr[s - 1] <= arr[s])
            s--;
        while(e < n - 1 && arr[e + 1] <= arr[e])
            e++;
        mx = max(mx, e - s + 1);
    }
    cout << mx << endl;
    return 0;
}