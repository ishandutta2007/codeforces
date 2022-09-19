#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int w, n, fen[c];
long long ans;
int lsb(int a) {
    return (a & -a);
}
void add(int a, int b) {
    //cout << "add " << a << " " << b << "\n";
    while (a<=n) {
        fen[a]+=b;
        a+=lsb(a);
    }
}
int ask(int a) {
    int ans=0;
    while (a) {
        ans+=fen[a];
        a-=lsb(a);
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        long long ans=0;
        cin >> n;
        for (int i=0; i<n; i++) {
            int x;
            cin >> x;
            ans+=i-ask(x-1);
            add(x, 1);
        }
        cout << ans << "\n";
        for (int i=0; i<=n; i++) {
            fen[i]=0;
        }
    }
    return 0;
}