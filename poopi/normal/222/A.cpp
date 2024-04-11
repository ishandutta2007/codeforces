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
int arr[200010];
int mn, mx;
set <int> st;

int gcd(int a, int b){
    return (b == 0 ? a : gcd(b, a % b));
}

int main(){
    int k;
    cin >> n >> k;
    k--;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int p = n - 1;
    while(p > 0 && arr[p - 1] == arr[n - 1])
        p--;
    if(k < p) cout << -1 << endl;
    else cout << p << endl;
    return 0;
}