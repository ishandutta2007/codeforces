#include <cstdio>
#include <iostream>

using namespace std;

typedef long long int llint;

const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

llint a,b,c,x,y,wx,wy;

int main(){
    cin >> x >> y;
    cin >> a >> b >> c;
    wx = 2 * a + b;
    wy = 3 * c + b;
    cout << max(0LL, wx - x) + max(0LL, wy - y) << endl;
}