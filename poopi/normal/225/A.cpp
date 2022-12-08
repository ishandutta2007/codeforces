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
int arr[100010];
int mn, mx;
set <int> st;

int gcd(int a, int b){
    return (b == 0 ? a : gcd(b, a % b));
}

int main(){
    int t, a, b;
    cin >> n >> t;
    t = min(t, 7 - t);
    string res = "YES";
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        a = min(a, 7 - a);
        b = min(b, 7 - b);
        if(t == a || t == b)
            res = "NO";
    }
    cout << res << endl;
    return 0;
}