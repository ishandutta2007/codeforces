#include <iostream>
using namespace std;
signed main (){
    int n; cin >> n;
    if (n % 2 == 0) cout << n + 228 << " " << 228;
    else cout << n + 1337 << " " << 1337;
    return 0;
}