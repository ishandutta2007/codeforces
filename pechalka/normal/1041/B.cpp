#include <iostream>

using namespace std;

long long gcd (long long a, long long b){
    if (b > 0)
        return gcd (b, a % b);
    else
        return a;
}

int main(){
    long long a, b, x, y;
    cin >> a >> b >> x >> y;
    long long d = gcd (x, y);
    long long v1 = a / (x / d), v2 = b / (y / d);
    if (v1 < v2)
        cout << v1;
    else
        cout << v2;
}