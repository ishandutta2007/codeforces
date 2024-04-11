#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n,k;
    cin >> n >> k;
    long long maxx=n+n-1;
    if(k>maxx)
    {
        printf("0\n");
        return 0;
    }
    if(k<=n+1)
    {
        cout << (k-1)/2 << endl;
        return 0;
    }
    cout << n-k/2 << endl;
    return 0;
}