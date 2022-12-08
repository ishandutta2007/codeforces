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

using namespace std;

#define int64 long long
#define P pair<int, int>
#define Inf 1000000000

int n, h;
int arr[100010];
int inv[100010];
vector <P> pnt;

int main(){
    cin >> n >> h;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        pnt.push_back(P(arr[i], i));
    }
    if(n == 2){
        cout << 0 << endl << "1 1" << endl;
        return 0;
    }
    sort(pnt.begin(), pnt.end());
    for(int i = 0; i < n; i++){
        arr[i] = pnt[i].first;
        inv[pnt[i].second] = i;
    }
    int idx = 0;
    int res = (arr[n - 1] + arr[n - 2]) - (arr[1] + arr[0]);
    int tmp = max(arr[n - 1] + arr[n - 2], arr[n - 1] + arr[0] + h) - min(arr[1] + arr[0] + h, arr[1] + arr[2]);
    if(res > tmp){
        res = tmp;
        idx = n - 1;
    }
    for(int i = 1; i < n - 1; i++){
        int mx = arr[n - 1] + arr[i] + h;
        if(i < n - 2)
            mx = max(mx, arr[n - 1] + arr[n - 2]);

        int mn = min(arr[0] + arr[1] + h, arr[0] + arr[i + 1]);
        if(i > 1)
            mn = min(mn, arr[1] + arr[2]);

        if(res > mx - mn){
            res = mx - mn;
            idx = i;
        }
    }
    cout << res << endl;
    for(int i = 0; i < n; i++){
        if(i != 0) cout << ' ';
        if(inv[i] > 0 && inv[i] <= idx)
            cout << 2;
        else cout << 1;
    }
    cout << endl;
    return 0;
}