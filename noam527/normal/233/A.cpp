#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    if (n & 1) return cout << -1 << endl, 0;
    for (; n >= 1; n--) cout << n << " ";
}