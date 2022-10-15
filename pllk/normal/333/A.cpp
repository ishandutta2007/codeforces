#include <iostream>

#define ll long long

using namespace std;

int main() {
    ll n;
    cin >> n;
    ll b = 3;
    while (n%b == 0) b *= 3;
    cout << (n/b+1)<< endl;
}