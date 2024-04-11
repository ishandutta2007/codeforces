#include <iostream>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int a, b, c, n;
    cin >> a >> b >> c >> n;
    bool pos = true;
    if (a < c || b < c)
        pos = false;
    if (a + b - c > n || n - a - b + c == 0)
        pos = false;
    if (pos)
        cout << n - a - b + c;
    else
        cout << -1;
    return 0;
}