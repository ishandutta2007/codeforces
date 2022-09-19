#include <bits/stdc++.h>

using namespace std;
const int c=300002;
int n, t[c], cs1, cs2, db;
bool v[c];
mt19937 rnd(time(NULL));
int vel(){
	return rnd()%(n)+1;
}
int kerd(int a, int b, int c) {
    if (a!=b && a!=c && b!=c) {
        db++;
        cout.flush() << "? " <<  a << " " << b << " " << c << "\n";
        int x; cin >> x;
        if (x!=a && x!=b && x!=c && !v[x]) {
            v[x]=1;
            db--;
        }
        return x;
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    n=(1<<n)-1;

    while (db<420) {
        int x=kerd(vel(), vel(), vel());
        t[x]++;
    }
    t[0]=0;
    for (int i=1; i<=n; i++) {
        if (v[i] && t[i]>t[cs2]) {
            cs2=i;
        }
        if (t[cs2]>t[cs1]) swap(cs1, cs2);
    }
    for (int i=1; i<=n; i++) {
        if (i!=cs1 && i!=cs2 && !v[i] && kerd(cs1, cs2, i)==i) {
            cout.flush() << "! " << i << "\n";
            return 0;
        }
    }
    return 0;
}