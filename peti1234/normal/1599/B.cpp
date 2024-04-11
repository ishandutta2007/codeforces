
#include <bits/stdc++.h>

using namespace std;
long long w, n, a, b, da, db;
string s, s2;
bool jo;
void v0() {
    if (!jo) {
        cout << 0 << "\n";
        jo=1;
    }
}
void v1() {
    if (!jo) {
        cout << n-1 << "\n";
        jo=1;
    }
}
void valt() {
    if (a==1 && da==-1 || a==n && da==1) {
        da*=-1;
    }
    if (b==1 && db==-1 || b==n && db==1) {
        db*=-1;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> a >> b;
        a++, b++;
        cin >> s >> s2;
        da=(s=="left" ? -1 : 1);
        db=(s2=="left" ? -1 : 1);
        valt();
        if (a+da==b) {
            a=b;
            swap(da, db);
        }
        if (a!=b) {
            while (da==db || a<b && da==-1 || b<a && db==-1) {
                long long ta=(da==1 ? n-a : a-1), tb=(db==1 ? n-b : b-1), lep=min(ta, tb);
                a+=lep*da, b+=lep*db;
                valt();
            }
            long long koz=(a+b)/2;
            if ((a+b)%2 && a<b) {
                koz++;
            }
            if ((a+b)%2) {
                swap(da, db);
            }
            a=b=koz;
        }
        valt();
        if (a==1) v1();
        if (a==n) v0();
        if (da==db) {
            if (da==1) v0();
            else v1();
        }
        if (da==-1) v0();
        else v1();
        jo=0;
    }
    return 0;
}