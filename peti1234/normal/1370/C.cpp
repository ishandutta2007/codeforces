#include <bits/stdc++.h>

using namespace std;
int w;
long long n, q, k;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n, k=-1, q=1;
        while(n%2==0) n/=2, q*=2;
        for (int i=3; i*i<=n; i+=2) if (n%i==0) k=i;
        if ((q==1 && n!=1) || (q>=4 && n!=1) || (q==2 && (k!=-1 || n==1))) cout << "Ashishgup\n";
        else cout << "FastestFinger\n";
    }
    return 0;
}