#include <bits/stdc++.h>

using namespace std;
int q;
int main()
{
    cin >> q;
    for (int i=1; i<=q; i++) {
        int l, r;
        cin >> r >> l;
        long long sum=0;
        if ((l-r)%2==0) {
            if (l%2==0) {
                sum+=l;
            } else {
                sum-=l;
            }
            l--;
        }

        int x=(l-r+1)/2;
        if (r%2==0) {
            sum-=x;
        } else {
            sum+=x;
        }
        cout << sum << endl;
    }
    return 0;
}