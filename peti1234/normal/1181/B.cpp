#include <bits/stdc++.h>

using namespace std;
const int c=100005;
int n, t[c], ans1[c], ans2[c], pos, s1, s2;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        char c;
        cin >> c;
        t[i]=(c-'0');
    }
    pos=(n+1)/2, s1=pos, s2=pos+1;
    while (t[s1]==0) {
        s1--;
    }
    while (s2<=n && t[s2]==0) {
        s2++;
    }
    for (int i=s1; i<=n; i++) {
        ans1[i]=t[i];
    }
    for (int i=s1-1; i>=1; i--) {
        ans1[n+i-s1+1]+=t[i];
    }
    for (int i=n; i>=1; i--) {
        if (ans1[i]>=10) {
            ans1[i]-=10;
            ans1[i-1]++;
        }
    }
    for (int i=s2; i<=n; i++) {
        ans2[i]=t[i];
    }
    for (int i=s2-1; i>=1; i--) {
        ans2[n+i-s2+1]+=t[i];
    }
    for (int i=n; i>=1; i--) {
        while (ans2[i]>=10) {
            ans2[i]-=10;
            ans2[i-1]++;
        }
    }

    int ert=2;
    for (int i=1; i<=n; i++) {
        if (ans1[i]<ans2[i]) {
            ert=1;
            break;
        }
        if (ans2[i]<ans1[i]) {
            break;
        }
    }
    if (ert==1) {
        bool f=0;
        for (int i=1; i<=n; i++) {
            if (ans1[i]) {
                f=1;
            }
            if (f) {
                cout << ans1[i];
            }
        }
    }

    if (ert==2) {
        bool f=0;
        for (int i=1; i<=n; i++) {
            if (ans2[i]) {
                f=1;
            }
            if (f) {
                cout << ans2[i];
            }
        }
    }
    return 0;
}