#include <iostream>

using namespace std;

typedef long long ll;
#define M 1000000007

int main() {
    int n;
    cin >> n;
    ll a = 1;
    for (int i = 2; i <= n; i++) a = a*i%M;
    ll b = 1;
    for (int i = 1; i <= n-1; i++) b = b*2%M;
    ll r = ((a-b)%M+M)%M;
    cout << r << "\n";
}