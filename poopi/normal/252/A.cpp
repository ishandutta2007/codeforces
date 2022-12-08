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
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int mx = 0;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            int t = 0;
            for(int k = i; k <= j; k++)
                t ^= arr[k];
            mx = max(mx, t);
        }
    }
    cout << mx << endl;
    return 0;
}