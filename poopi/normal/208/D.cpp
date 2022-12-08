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

int n;
int64 arr[100010];
int64 c[10], t[10];

int main(){
    int64 sum = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < 5; i++)
        cin >> c[i];
    for(int i = 0; i < n; i++){
        sum += arr[i];
        for(int j = 4; j >= 0; j--){
            int x = sum / c[j];
            t[j] += x;
            sum %= c[j];
        }
    }
    for(int i = 0; i < 5; i++)
        cout << t[i] << ' ';
    cout << endl << sum << endl;
    return 0;
}