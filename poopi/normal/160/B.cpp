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
    int a[200], b[200];
    cin >> n;
    char ch;
    for(int i = 0; i < n; i++){
        cin >> ch;
        a[i] = ch - '0';
    }
    for(int i = 0; i < n; i++){
        cin >> ch;
        b[i] = ch - '0';
    }
    sort(a, a + n);
    sort(b, b + n);
    bool g = false, l = false;
    for(int i = 0; i < n; i++){
        if(a[i] <= b[i])
            l = true;
        if(a[i] >= b[i])
            g = true;
    }
    cout << (g && l ? "NO" : "YES") << endl;
    return 0;
}