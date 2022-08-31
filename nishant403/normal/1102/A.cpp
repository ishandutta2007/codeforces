#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long n;
    cin >> n;
    
    long long k= (n*(n+1))/2;
    if(k%2==0) cout << 0;
    else cout << 1;
    
    
    
    
    return 0;
}