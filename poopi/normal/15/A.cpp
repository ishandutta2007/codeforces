                /* in the name of Allah */
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

#define P pair<int, int>

int n, t;
P arr[1010];

int main(){
    int cnt = 2;
    cin >> n >> t;
    for(int i = 0; i < n; i++)
        cin >> arr[i].first >> arr[i].second;
    sort(arr, arr + n);
    for(int i = 1; i < n; i++){
        int dif = (arr[i].first - arr[i-1].first) * 2 - arr[i].second - arr[i-1].second;
        if(2 * t <= dif)
            cnt++;
        if(2 * t < dif)
            cnt++;
    }
    cout << cnt << endl;
    return 0;
}