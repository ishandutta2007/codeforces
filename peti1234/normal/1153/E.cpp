#include <bits/stdc++.h>

using namespace std;
int n;
int sa, sb, oa, ob;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cout.flush() << "?" << " " << i << " " << 1 << " " << i << " " << n << endl;
        int x;
        cin >> x;
        if (x%2!=0) {
            if (sa==0) {
                sa=i;
            } else {
                sb=i;
            }
        }
    }
    for (int i=1; i<=n; i++) {
        cout.flush() << "?" << " " << 1 << " " << i << " " << n << " " << i << endl;
        int x;
        cin >> x;
        if (x%2!=0) {
            if (oa==0) {
                oa=i;
            } else {
                ob=i;
            }
        }
    }
    if (sa!=0 && oa!=0) {
        cout.flush() << "?" << " " << sa << " " << oa << " " << sa << " " << oa << endl;
        int x;
        cin >> x;
        if (x%2==0) {
            cout << "!" << " " << sa << " " << ob << " " << sb << " " << oa << endl;
        } else {
            cout << "!" << " " << sa << " " << oa << " " << sb << " " << ob << endl;
        }
        return 0;
    }
    int l=1; int u=n+1;
    if (sa==0) {
        while(u-l>1) {
            int p=(u+l)/2;
            cout.flush() << "?" << " " << l << " " << 1 << " " << p-1 << " " << oa << endl;
            int x;
            cin >> x;
            if (x%2==1) {
                u=p;
            } else {
                l=p;
            }
        }
        cout << "! " << l << " " << oa << " " << l << " " << ob << endl;
        return 0;
    }
    if (oa==0) {
        while(u-l>1) {
            int p=(u+l)/2;
            cout.flush() << "?" << " " << 1 << " " << l << " " << sa << " " << p-1 << endl;
            int x;
            cin >> x;
            if (x%2==1) {
                u=p;
            } else {
                l=p;
            }
        }
        cout << "! " << sa << " " << l << " " << sb << " " << l << endl;
        return 0;
    }
    return 0;
}