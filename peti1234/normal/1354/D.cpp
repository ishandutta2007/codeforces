#include <bits/stdc++.h>
#define lsb(i) ((i) & -(i))
using namespace std;
int n, q, x;
int db[1000002], p[1000002];
void add(int a, int b) {
    p[a]+=b;
    while(a<=n) db[a]+=b, a+=lsb(a);
}
int ask(int a) {
    int sum=0;
    while(a) sum+=db[a], a-=lsb(a);
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    for (int i=1; i<=n; i++) {
        cin >> x;
        add(x, 1);
    }
    for (int i=1; i<=q; i++) {
        cin >> x;
        int f;
        if (x>0) f=1;
        else f=-1;
        x=abs(x);
        if (f==-1) {
            int l=0, h=n;
            while(h-l>1) {
                int m=(h+l)/2;
                if (ask(m)>=x) h=m;
                else l=m;
            }
            add(h, f);
        } else add(x, f);
    }
    for(int i=1; i<=n; i++) {
        if (p[i]) {
            cout << i << "\n";
            return 0;
        }
    }
    cout << 0 << "\n";
    return 0;
}