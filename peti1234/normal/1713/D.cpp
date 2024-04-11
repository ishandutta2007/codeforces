#include <bits/stdc++.h>

using namespace std;
int kerd(int a, int b) {
    cout.flush() << "? " << a << " " << b << "\n";
    int x;
    cin >> x;
    if (x==0) return 0;
    if (x==1) return a;
    if (x==2) return b;
}
int solve() {
    int n;
    cin >> n;
    vector<int> regi, uj;
    for (int i=1; i<=(1<<n); i++) {
        regi.push_back(i);
    }
    while (regi.size()>1) {
        int si=regi.size();
        if (si==2) {
            return kerd(regi[0], regi[1]);
        }
        for (int i=0; i<si; i+=4) {
            int a=regi[i], b=regi[i+1], c=regi[i+2], d=regi[i+3];
            int x=kerd(a, c);
            if (x==a) uj.push_back(kerd(a, d));
            if (x==c) uj.push_back(kerd(b, c));
            if (x==0) uj.push_back(kerd(b, d));
        }
        swap(regi, uj);
        uj.clear();
    }
    return regi[0];
}
int main()
{
    int w;
    cin >> w;
    while (w--) {
        int ans=solve();
        cout.flush() << "! " << ans << "\n";
    }
    return 0;
}