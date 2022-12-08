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
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        cnt += arr[i];
    }
    sort(arr, arr + n);
    reverse(arr, arr + n);
    int p = 0, sum = 0;
    while(sum <= cnt - sum)
        sum += arr[p++];
    cout << p << endl;
    return 0;
}