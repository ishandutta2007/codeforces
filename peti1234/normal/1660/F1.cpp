#include <bits/stdc++.h>

using namespace std;
const int c=500005;
int w, n, fen[c];
string s;
int lsb(int a) {
    return (a & -a);
}
void add(int a, int b) {
    while (a<c) {
        fen[a]+=b;
        a+=3*lsb(a/3);
    }
}
int ask(int a) {
    int sum=0;
    while (a>=3) {
        sum+=fen[a];
        a-=3*lsb(a/3);
    }
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        cin >> s;
        long long ans=0;
        int ert=c/2;
        add(ert, 1);
        for (auto c:s) {
            if (c=='-') ert++;
            else ert--;
            ans+=ask(ert);
            add(ert, 1);
        }

        ert=c/2;
        add(ert, -1);
        for (auto c:s) {
            if (c=='-') ert++;
            else ert--;
            add(ert, -1);
        }

        cout << ans << "\n";
    }
    return 0;
}