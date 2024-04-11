                /* in the name of Allah */
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n, d;
int arr[2010];

int main(){
    cin >> n >> d;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(i == 0 || arr[i] > arr[i-1]) continue;
        int dif = arr[i-1] - arr[i] + 1;
        int t = (dif + d - 1) / d;
        cnt += t;
        arr[i] += t * d;
    }
    cout << cnt << endl;
    return 0;
}