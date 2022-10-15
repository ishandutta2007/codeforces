#include <iostream>

using namespace std;

#define lli long long int

int main(void) {
    int n, m, a;
    cin >> n >> m >> a;
    lli x = (n-1)/a+1;
    lli y = (m-1)/a+1;
    cout << x*y << endl;
}