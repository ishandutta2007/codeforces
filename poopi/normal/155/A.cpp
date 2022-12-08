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
int mn, mx;
set <char> st;

int gcd(int a, int b){
    return (b == 0 ? a : gcd(b, a % b));
}

int main(){
    int a;
    cin >> n >> a;
    mn = mx = a;
    for(int i = 1; i < n; i++){
        cin >> a;
        if(a > mx){
            mx = a;
            cnt++;
        }
        if(a < mn){
            mn = a;
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}