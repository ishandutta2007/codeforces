#include <bits/stdc++.h>

using namespace std;
int t;
long long n, k;
long long p=1;
long long r=0;
bool sok(long long a, long long b)
{
    if (b==0) {
        return false;
    }
    if (a==0) {
        return true;
    }
    if (b==1) {
        return false;
    }
    return sok(a-1, (b-2)/4+1);
}
int main()
{
    cin >> t;
    for (int i=1; i<=t; i++) {
        cin >> n >> k;
        r=0;
        p=1;
        if (sok (n, k)) {
            cout << "NO" << endl;
            continue;
        }
        while(k>=p && r<n) {
            k-=p;
            p*=2;
            r++;
            p++;
        }
        //cout << k << " " << p << " " << r << " " << n << endl;
        if (r==1) {
            if (n==2 && k==2) {
                cout << "NO" << endl;
                continue;
            } else {
                cout << "YES" << " " << n-r << endl;
                continue;
            }
        }
        /*if (r==2) {
            if (n==3 && k>1) {
                cout << "NO" << endl;
                continue;
            } else {
                cout << "YES" << " " << n-r-1 << endl;
                continue;
            }
        }
        if (r==3) {
            if (n==4 && k>10) {
                cout << "NO" << endl;
                continue;
            } else {
                cout << "YES" << " " << n-r << endl;
                continue;
            }
        }*/
        cout << "YES" << " " << n-r << endl;
        continue;
    }
    return 0;
}