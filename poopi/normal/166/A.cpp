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
P arr[100010];
int mn, mx;
set <int> st;

int gcd(int a, int b){
    return (b == 0 ? a : gcd(b, a % b));
}

int main(){
    int k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> arr[i].first >> arr[i].second;
        arr[i].first *= -1;
    }
    sort(arr, arr + n);
    int s = k - 1, e = k - 1;
    while(s > 0 && arr[s - 1] == arr[k - 1])
        s--;
    while(e < n - 1 && arr[e + 1] == arr[k - 1])
        e++;
    cout << e - s + 1 << endl;
    return 0;
}