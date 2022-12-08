                            /* in the name of Allah */
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <ctime>
#include <set>
using namespace std;

#define int64 long long
#define P pair<int, int>

int n, cnt;
int arr[210];
int mn, mx;
set <int> st;

int gcd(int a, int b){
    return (b == 0 ? a : gcd(b, a % b));
}

int main(){
    int k;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    reverse(arr, arr + n);
    if(k > n) cout << -1 << endl;
    else if(k == n || arr[k - 1] != arr[k])
        cout << arr[k - 1] << ' ' << arr[k - 1] << endl;
    else cout << -1 << endl;
    return 0;
}