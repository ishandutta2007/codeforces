#include <cstdio>
#include <iostream>

using namespace std;

int a, b;

int main() {
    cin >> a >> b;
    int ans = 0;
    int o = 0;
    while (a > 0) {
        ans += a;
        int temp = a;
        a = (a + o) / b;
        o = (temp + o) % b;
    }
    cout << ans;
    
    return 0;
}