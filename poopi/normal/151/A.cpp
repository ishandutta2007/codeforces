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
P arr[210];
bool mark[210][4];
int mn, mx;
string str;
set <int> st;

int gcd(int a, int b){
    return (b == 0 ? a : gcd(b, a % b));
}

int main(){
    int k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;
    int t1 = k * l / nl / n;
    int t2 = c * d / n;
    int t3 = p / np / n;
    cout << min(t1, min(t2, t3)) << endl;
    return 0;
}