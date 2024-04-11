                /* in the name of Allah */
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int gcd(int a, int b){
    return (b == 0 ? a : gcd(b, a % b));
}

int main(){
    int a, b;
    cin >> a >> b;
    int d = gcd(7 - max(a, b), 6);
    cout << (7 - max(a, b)) / d << '/' << 6 / d << endl;
    return 0;
}