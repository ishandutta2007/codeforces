#include <bits/stdc++.h>

using namespace std;
const int c=100005, k=300;
int n, q, kov[c], el[c], nagy[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        kov[i]=x, el[x]=i;
    }
    for (int i=1; i<=n; i++) {
        int s=i;
        for (int j=0; j<k; j++) {
            s=kov[s];
        }
        nagy[i]=s;
    }
    for (int ii=1; ii<=q; ii++) {
        int id, a, b;
        cin >> id >> a >> b;
        if (id==1) {
            swap(kov[a], kov[b]);
            el[kov[a]]=a, el[kov[b]]=b;
            int cel=a, st=a;
            for (int i=1; i<=k; i++) {
                st=el[st];
            }
            for (int i=0; i<=k; i++) {
                nagy[st]=cel;
                st=kov[st], cel=kov[cel];
            }
            cel=b, st=b;
            for (int i=1; i<=k; i++) {
                st=el[st];
            }
            for (int i=0; i<=k; i++) {
                nagy[st]=cel;
                st=kov[st], cel=kov[cel];
            }

        } else {
            while (b>=k) {
                a=nagy[a];
                b-=k;
            }
            while (b) {
                a=kov[a];
                b--;
            }
            cout << a << "\n";
        }
    }
    return 0;
}