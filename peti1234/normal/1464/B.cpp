#include <bits/stdc++.h>

using namespace std;
const int c=100002;
long long n, x, y, mini, ert;
long long db[c], ossz;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> s >> x >> y;
    n=s.size();
    for (int i=1; i<=n; i++) {
        db[i]=db[i-1];
        if (s[i-1]=='1') {
            ert+=ossz*x;
        } else {
            db[i]++;
            ossz++;
            ert+=(i-ossz)*y;
        }
    }
    //cout << "most " << ert << endl;
    mini=ert;
    // ? 0 helyett 1 lesz
    for (int i=1; i<=n; i++) {
        db[i]=db[i-1];
        if (s[i-1]=='0') {
            db[i]++;
        }
        if (s[i-1]=='?') {
            ossz--;
            // 10
            ert-=(i-1-db[i-1])*y;
            // 01
            ert+=db[i-1]*x;
            // 01 i-tl
            ert-=(n-ossz-(i-db[i-1]))*x;
            // 10 i-tl
            ert+=(ossz-db[i-1])*y;
            mini=min(mini, ert);

            //cout << "valt " << i << " " << ert << endl;
            /*
            cout << "10 " << i-1-db[i-1] << "\n";
            cout << "01 " << db[i-1] << "\n";
            cout << "01 " << n-ossz-(i-db[i-1]) << "\n";
            cout << "10 " << ossz-db[i-1] << "\n";
            */
            //return 0;
        }
    }
    // ? 1 helyett 0 lesz
    for (int i=1; i<=n; i++) {
        db[i]=db[i-1];
        if (s[i-1]=='0') {
            db[i]++;
        }
        if (s[i-1]=='?') {
            ossz++, db[i]++;
            // 10
            ert+=(i-1-db[i-1])*y;
            // 01
            ert-=db[i-1]*x;
            // 01 i-tl
            ert+=(n-ossz-(i-db[i]))*x;
            // 10 i-tl
            ert-=(ossz-db[i])*y;
            mini=min(mini, ert);
            /*
            cout << "valt " << i << " " << ert << endl;
            cout << "10 " << i-1-db[i-1] << "\n";
            cout << "01 " << db[i-1] << "\n";
            cout << "01 " << n-ossz-(i-db[i-1]) << "\n";
            cout << "10 " << ossz-db[i-1] << "\n";
            */
        }
    }
    cout << mini << "\n";
    return 0;
}
/*
01101001
5 7
*/