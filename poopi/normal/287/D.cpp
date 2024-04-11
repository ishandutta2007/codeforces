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
int arr[2000010];

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        arr[i] = i + 1;
    int s = 0;
    for(int i = 2; i <= n; i++){
        int tmp = arr[s];
        for(int j = s + i; j < s + n; j += i){
            swap(tmp, arr[j]);
        }
        arr[s + n] = tmp;
        s++;
    }
    for(int i = s; i < n + s; i++)
        cout << arr[i] << ' ';
    cout << endl;
    return 0;
}