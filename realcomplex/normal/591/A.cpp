#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fi first
#define se second


int main()
{
    double n,sph,spv;
    cin >> n >> sph >> spv;
    double total = sph + spv;
    double pos = (n / total) * sph;
    cout << setprecision(15) << pos;
    return 0;
}