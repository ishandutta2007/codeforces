#include <iostream>

using namespace std;

#define ll long long int

#define M 1000000007

using namespace std;

int n, k;

ll d[8] = {1,1,3,16,125,1296,16807,262144};
ll t;

int main() {
    cin >> n >> k;
    t = k;
    t *= d[k-1];
    t %= M;
    for (int i = k+1; i <= n; i++) {
        t *= (n-k);
        t %= M;
    }
    cout << t << endl;
}