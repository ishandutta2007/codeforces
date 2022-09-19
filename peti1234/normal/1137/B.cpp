#include <bits/stdc++.h>

using namespace std;
string s, t;
long long x, y, xx, yy, h=1, hh=1;;
int a, b;
int maxi=0;
int n;
long long m=1000000007;
long long mm=1000000009;
int main()
{
    cin >> s >> t;
    n=t.size();
    for (int i=0; i<n-1; i++) {
        x*=2;
        x+=t[i]-'0';
        xx*=2;
        xx+=t[i]-'0';
        y+=h*(t[n-i-1]-'0');
        h*=2;
        yy+=hh*(t[n-i-1]-'0');
        hh*=2;
        x%=m, xx%=mm, y%=m, yy%=mm, h%=m, hh%=mm;
        if (x==y && xx==yy) {
            maxi=i+1;
        }
    }
    for (int i=0; i<s.size(); i++) {
        if (s[i]=='0') {
            a++;
        } else {
            b++;
        }
    }
    for (int i=0; i<maxi; i++) {
        if (a==0 || b==0) {
            break;
        }
        int q=t[i]-'0';
        cout << q;
        if (q==0) {
            a--;
        } else {
            b--;
        }
    }
    while(a>0 && b>0) {
        for (int i=maxi; i<n; i++) {
            if (a==0 || b==0) {
            break;
        }
        int q=t[i]-'0';
        cout << q;
        if (q==0) {
            a--;
        } else {
            b--;
        }
        }
    }
    for (int i=1; i<=a; i++) {
        cout << 0;
    }
    for (int i=1; i<=b; i++) {
        cout << 1;
    }
    //cout << maxi << " " << a << " " << b << "\n";
    return 0;
}