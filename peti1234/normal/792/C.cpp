#include <bits/stdc++.h>

using namespace std;
int n, t[100005], sum, sa, sb, db;
vector<int> a, b;
string s;
int main()
{
    cin >> s;
    n=s.size();
    for (int i=1; i<=n; i++) {
        t[i]=(s[i-1]-'0');
        sum+=t[i];
        if (t[i]%3==1) a.push_back(i);
        if (t[i]%3==2) b.push_back(i);
        if (t[i]) db++;
    }
    sa=a.size(), sb=b.size();
    if (sum%3==0) {
        cout << s << "\n";
        return 0;
    }
    if (db==1) {
        cout << (n==1 ? -1 : 0) << "\n";
        return 0;
    }
    if (db==2) {
        if (sa==2 || sb==2) {
            cout << (n==2 ? -1 : 0) << "\n";
            return 0;
        }
        bool jo=0;
        for (int i=1; i<=n; i++) {
            if (t[i]%3==0 && (t[i] || jo)) {
                cout << t[i];
                if (t[i]) {
                    jo=1;
                }
            }
        }
        cout << "\n";
        return 0;
    }
    if (sum%3==1) {
        if (sa) {
            if (a.back()>1 || t[2]!=0) {
                for (int i=1; i<=n; i++) {
                    if (i!=a.back()) {
                        cout << t[i];
                    }
                }
                cout << "\n";
                return 0;
            } else if (sb>1) {
                for (int i=1; i<=n; i++) {
                    if (i!=b[sb-2] && i!=b[sb-1]) {
                        cout << t[i];
                    }
                }
                cout << "\n";
                return 0;
            } else {
                bool jo=0;
                for (int i=2; i<=n; i++) {
                    if (t[i]) {
                        jo=1;
                    }
                    if (jo) {
                        cout << t[i];
                    }
                }
                cout << "\n";
                return 0;
            }
        } else {
            bool jo=0;
            for (int i=1; i<=n; i++) {
                if (i!=b[sb-2] && i!=b[sb-1] && (jo || t[i])) {
                    cout << t[i];
                    if (t[i]) {
                        jo=1;
                    }
                }
            }
            cout << "\n";
            return 0;
        }
    }
    if (sum%3==2) {
        if (sb) {
            if (b.back()>1 || t[2]!=0) {
                for (int i=1; i<=n; i++) {
                    if (i!=b.back()) {
                        cout << t[i];
                    }
                }
                cout << "\n";
                return 0;
            } else if (sa>1) {
                for (int i=1; i<=n; i++) {
                    if (i!=a[sa-2] && i!=a[sa-1]) {
                        cout << t[i];
                    }
                }
                cout << "\n";
                return 0;
            } else {
                bool jo=0;
                for (int i=2; i<=n; i++) {
                    if (t[i]) {
                        jo=1;
                    }
                    if (jo) {
                        cout << t[i];
                    }
                }
                cout << "\n";
                return 0;
            }
        } else {
            bool jo=0;
            for (int i=1; i<=n; i++) {
                if (i!=a[sa-2] && i!=a[sa-1] && (jo || t[i])) {
                    cout << t[i];
                    if (t[i]) {
                        jo=1;
                    }
                }
            }
            cout << "\n";
            return 0;
        }
    }
    return 0;
}