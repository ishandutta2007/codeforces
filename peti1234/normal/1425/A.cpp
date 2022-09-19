#include <bits/stdc++.h>

using namespace std;
int w;
long long n, sum;
long long lep() {
    if (n%4==2 || n==4) {
        n/=2;
        return n;
    }
    n--;
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n, sum=0;
        while(n>0) {
            sum+=lep();
            lep();
        }
        cout << sum << "\n";
    }
    return 0;
}