#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int k=1;
    int p=0;
    while(n>=k) {
        n-=k;
        k*=2;
        p++;
    }
    if (n>0) {
        p++;
    }
    cout << p << endl;
    return 0;
}