#include <bits/stdc++.h>

using namespace std;
const int c=302;
int n, el, mo, uk, pos=1, valt[c], db, cnt;
bool ans[c];
void val() {
    cout << "! ";
    for (int i=1; i<=n; i++) cout << ans[i];
    cout << "\n";
}
int kerd(int a, int b) {
    cout.flush() << "? " << a << " " << b << "\n";
    int x; cin >> x;
    return x;
}
int main()
{
    cin >> n >> el, db=el;
    if (n%2==0) {
        while(pos<n) {
            mo=kerd(pos, pos);
            if (abs(mo-el)%2==pos%2) {
                if (mo-el<-uk) valt[pos]++;
                ans[pos]=valt[pos]%2;
                uk=mo-el, cnt+=ans[pos], pos++;
            } else for (int i=pos; i<=n; i++) valt[i]++;
            el=mo;
        }
        if (cnt<db) ans[n]=1;
        val();
    } else {
        pos=2;
        while(pos<=n/2+1) {
            mo=kerd(pos, pos+1);
            if ((abs(mo-el))%2==pos%2) {
                for (int i=pos; i<=n; i++) valt[i]++;
                int ert=el+mo-n+pos-1;
                ert/=2;
                for (int i=1; i<pos; i++) ert-=(valt[i]+ans[i])%2;
                ans[pos-1]=ert, cnt+=ans[pos-1], pos++;
            } else for (int i=1; i<=pos+1; i++) valt[i]++;
            el=mo;
        }
        pos=n-2;
        while(pos>=n/2) {
            mo=kerd(pos, pos+1);
            if ((abs(mo-el))%2!=pos%2) {
                for (int i=1; i<=pos+1; i++) valt[i]++;
                int ert=el+mo-pos-1;
                ert/=2;
                for (int i=pos+2; i<=n; i++) ert-=(valt[i]+ans[i])%2;
                ans[pos+2]=ert, cnt+=ans[pos+2], pos--;
            } else for (int i=pos; i<=n; i++) valt[i]++;
            el=mo;
        }
        if (cnt<db) ans[n/2+1]=1;
        val();
    }
    return 0;
}