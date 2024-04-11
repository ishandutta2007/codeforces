#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int main(){
    int H, L;
    cin >> H >> L;
    long double ans = (long double)((long long)L * L - (long long)H * H) / 2 / H;
    cout << setprecision(100) << ans;
    return 0;
}