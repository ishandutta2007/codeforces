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

int n, cnt = -1000000000;
P arr[200];
int mn, mx;
string str;
set <int> st;

int gcd(int a, int b){
    return (b == 0 ? a : gcd(b, a % b));
}

int main(){
    int k, f, t;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> f >> t;
        cnt = max(cnt, f - max(0, t - k));
    }
    cout << cnt << endl;
    return 0;
}