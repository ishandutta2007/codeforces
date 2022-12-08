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
    int64 a, b, c;
    cin >> a >> b >> c;
    int64 t = a * b * c;
    t = sqrt((double)t) + 1e-9;
    a = t / a;
    b = t / b;
    c = t / c;
    cout << 4 * (a + b + c) << endl;
    return 0;
}