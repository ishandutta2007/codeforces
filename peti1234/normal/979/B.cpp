#include <bits/stdc++.h>

using namespace std;
int n, a, b, c, maxi, db, t[62];
int f() {
    string s; maxi=0;
    cin >> s;
    int si=s.size();
    for (int i=0; i<60; i++) t[i]=0;
    for (int i=0; i<si; i++) {
        char c=s[i];
        int x=c-'a', y=c-'A';
        if (x>=0 && x<=30) t[x]++;
        else t[30+y]++;
    }
    for (int i=0; i<60; i++) maxi=max(maxi, t[i]);
    if (n==1 && si==maxi && si>1) return si-1;
    return min(si, maxi+n);
}
int main()
{
    cin >> n;
    a=f(), b=f(), c=f();
    maxi=max({a, b, c});
    db=(a==maxi)+(b==maxi)+(c==maxi);
    if (db==1) {
        if (a==maxi) cout << "Kuro\n";
        if (b==maxi) cout << "Shiro\n";
        if (c==maxi) cout << "Katie\n";
    } else cout << "Draw\n";
    return 0;
}