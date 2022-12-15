#include <bits/stdc++.h>
using namespace std;
int a,m,k;

int main()
{
    cin >> a>>m;
    a=a%m;
    while (m%2==0) m/=2;
    if (a%m==0) cout << "Yes";
    else cout << "No";
    return 0;
}