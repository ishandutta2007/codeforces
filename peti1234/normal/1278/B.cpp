#include <bits/stdc++.h>

using namespace std;
int q;
int main()
{
    cin >> q;
    while(q--) {
        int a, b;
        cin >> a >> b;
        int c=abs(b-a);
        int sum=0;
        for (int i=0; i<=1000000; i++) {
            sum+=i;
            if (sum>=c && (sum-c)%2==0) {
                cout << i << "\n";
                break;
            }
        }
    }
    return 0;
}