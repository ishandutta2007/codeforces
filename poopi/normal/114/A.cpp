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
    int64 k, l, a = 1;
    cin >> k >> l;
    while(a < l){
        a *= k;
        cnt++;
    }
    if(a == l){
        cout << "YES" << endl;
        cout << cnt - 1 << endl;
    }
    else cout << "NO" << endl;
    return 0;
}