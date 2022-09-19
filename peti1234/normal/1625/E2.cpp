#include <bits/stdc++.h>

using namespace std;

const int c=300005;
long long n, q, fen[c][2], par[c], kov[c];
vector<int> sz;
long long f(long long x) {
    return x*(x+1)/2;
}
int lsb(int a) {
    return (a & -a);
}
void add(int a, int id, long long b) {
    while (a<=n) {
        fen[a][id]+=b;
        a+=lsb(a);
    }
}
long long ask(int a, int id) {
    long long ans=0;
    while (a) {
        ans+=fen[a][id];
        a-=lsb(a);
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    for (int i=1; i<=n; i++) {
        char c;
        cin >> c;
        if (c=='(') sz.push_back(i);
        if (c==')') {
            int cnt=0;
            while (sz.size()>0 && par[sz.back()]) {
                kov[sz.back()]=i;
                sz.pop_back();
                cnt++;
            }
            add(i, 0, -cnt);
            add(i, 1, f(cnt));
            if (sz.size()>0) {
                par[sz.back()]=i, par[i]=sz.back();
                add(sz.back(), 0, 1);
            }
        }
    }
    for (int i=1; i<=q; i++) {
        int id, l, r;
        cin >> id >> l >> r;
        if (id==1) {
            add(l, 0, -1);
            int s=kov[l];
            if (!s) continue;
            int cnt=ask(s-1, 0)-ask(s, 0);
            add(s, 0, 1), add(s, 1, f(cnt-1)-f(cnt));
        }
        if (id==2) {
            cout << ask(r, 1)-ask(l, 1)+f(ask(r, 0)-ask(l-1, 0)) << "\n";
        }

    }
    return 0;
}