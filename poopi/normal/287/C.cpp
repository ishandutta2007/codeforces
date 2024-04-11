                                    /* in the name of Allah */

#include <algorithm>
#include <iostream>
#include <memory.h>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <list>
#include <map>

using namespace std;

#define int64 long long
#define P pair<int, double>

int n;
int arr[100010];

int main(){
    cin >> n;
    if(n % 4 == 2 || n % 4 == 3){
        cout << "-1" << endl;
        return 0;
    }
    int rem = n, p = 0;
    while(rem > 1){
        arr[p] = p + 2;
        arr[p + 1] = n - p;
        arr[n - 1 - p] = n - p - 1;
        arr[n - 2 - p] = p + 1;
        p += 2;
        rem -= 4;
    }
    if(rem == 1)
        arr[p] = p + 1;
    for(int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << endl;
    return 0;
}