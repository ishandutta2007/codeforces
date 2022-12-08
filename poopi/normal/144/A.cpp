                            /* in the name of Allah */
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <ctime>
#include <set>
using namespace std;

#define int64 long long
#define P pair<int, int>

int n, cnt;
int arr[200];

int gcd(int a, int b){
    return (b == 0 ? a : gcd(b, a % b));
}

int main(){
    int mn = 1000, mx = 0;
    int f, l;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(arr[i] > mx){
            f = i;
            mx = arr[i];
        }
        if(arr[i] <= mn){
            l = i;
            mn = arr[i];
        }
    }
    cnt = f + n - 1 - l;
    if(f > l) cnt--;
    cout << cnt << endl;
    return 0;
}