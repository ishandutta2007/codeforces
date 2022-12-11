#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int main()
{
    int n;
    cin >> n;
    long double sum = 0;
    long double sk;
    for(int i = 0;i<n;i++){
        cin >> sk;
        sum += sk;
    }
    sum /= n;
    cout << setprecision(20) << sum;
    return 0;
}