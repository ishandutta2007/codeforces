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
    vector <int> v[3];
    cin >> n;
    int t, p = 0;
    for(int i = 0; i < n; i++){
        cin >> t;
        cnt += abs(t - p) + 2;
        p = t;
    }
    cout << cnt - 1 << endl;
    return 0;
}