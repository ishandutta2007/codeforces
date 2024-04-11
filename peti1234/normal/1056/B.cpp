#include <bits/stdc++.h>

using namespace std;
long long n, m;
long long sum;
int main()
{
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=m; j++) {
            if ((i*i+j*j)%m==0) {
                sum+=((n+m-i)/m)*((n-j+m)/m);
            }
        }
    }
    cout << sum << endl;
    return 0;
}