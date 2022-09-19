#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int lo=1, hi=n, add=0;
    while (hi-lo>1) {
        int mid=(hi+lo)/2;
        int s=n-(add+mid)%n;
        cout.flush() << "+ " << s << endl;
        add+=s;
        int x;
        cin >> x;
        if (x==(mid+add)/n) lo=mid;
        else hi=mid;
    }
    cout.flush() << "! " << lo+add << endl;
    return 0;
}