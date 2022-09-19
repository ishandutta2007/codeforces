#include <bits/stdc++.h>

using namespace std;
int n, ans[200002];
pair<int, int> kerd(int a, int b) {
    cout.flush() << "? " <<  a << " " << b << "\n";
    pair<int, int> x;
    cin >> x.first >> x.second;
    return x;
}
void solve(int a, int b) {
    if (!ans[a]) ans[a]=kerd(a, a).first;
    if (!ans[b]) ans[b]=kerd(b, b).first;
    if (ans[a]==ans[b]) for (int i=a; i<b; i++) ans[i]=ans[a];
    else if (a+1<b) {
        pair<int, int> val=kerd(a, b);
        int fi=val.first, se=val.second, c=(a+b)/2;
        if (fi==ans[a]) {
            for (int i=1; i<se; i++) ans[i+a]=fi;
            solve(a+se, b);
        } else if (fi==ans[b]) {
            for (int i=b-se+1; i<b; i++) ans[i]=fi;
            solve(a, b-se);
        } else solve(a, c), solve(c, b);
    }
}
int main()
{
    cin >> n;
    solve(1, n);
    cout << "! ";
    for (int i=1; i<=n; i++) cout << ans[i] << " ";
    cout << "\n";
    return 0;
}