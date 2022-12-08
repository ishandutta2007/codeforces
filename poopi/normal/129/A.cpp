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
    cin >> n;
    int a, sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a;
        sum += a;
        if(a % 2) cnt++;
    }
    cout << (sum % 2 ? cnt : n - cnt) << endl;
    return 0;
}