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
int64 arr[210];
int mn, mx;
set <int> st;

int gcd(int a, int b){
    return (b == 0 ? a : gcd(b, a % b));
}

int main(){
    int k;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> k;
        arr[k + 10]++;
    }
    int64 res = arr[10] * (arr[10] - 1) / 2;
    for(int i = 0; i < 10; i++)
        res += arr[i] * arr[20 - i];
    cout << res << endl;
    return 0;
}