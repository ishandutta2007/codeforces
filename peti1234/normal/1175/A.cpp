#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    int q;
    cin >> q;
    for (int i=1; i<=q; i++) {
        long long n, k;
        long long st=0;
        cin >> n >> k;
        while(n>0) {
            long long a=n%k;
            st+=a;
            n-=a;
            n/=k;
            st++;
        }
        st--;
        cout << st << "\n";
    }
    return 0;
}