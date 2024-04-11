#include <bits/stdc++.h>

using namespace std;
const int c=100002;
int n, k, ans=1, db, x;
bool v[c], pr[c];
vector<int> kerd;
bool van(int a) {
    if (a>n) return 0;
    cout.flush() << "A " << a << "\n";
    cin >> x;
    int res=0;
    if (a==1) res=db;
    else {
        for (int i=a; i<=n; i+=a) res+=1-v[i];
    }
    return (x!=res);
}
void torol(int a) {
    cout.flush() << "B " << a << "\n";
    for (int i=a; i<=n; i+=a) if (!v[i]) v[i]=1, db--;
    cin >> x;
}
void valasz(int a) {
    cout << "C " << a << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    k=sqrt(n), db=n;
    for (int i=2; i<=n; i++) {
        if (!pr[i]) {
            for (int j=2*i; j<=n; j+=i) pr[j]=1;
        }
    }
    for (int i=k+1; i<=n; i++) {
        if (!pr[i]) torol(i), kerd.push_back(i);
        if (kerd.size()==100) {
            if (van(1)) {
                for (int i=0; i<100; i++) if (van(kerd[i])) ans*=kerd[i];
                kerd.clear();
                break;
            }
            kerd.clear();
        }
    }
    if (van(1)) {
        for (int i=0; i<kerd.size(); i++) if (van(kerd[i])) ans*=kerd[i];
        kerd.clear();
    }
    if (ans!=1) {
        for (int i=k; i>=1; i--) {
            if (van(ans*i)) {
                valasz(ans*i);
                return 0;
            }
        }
    }
    for (int i=2; i<=k; i++) {
        if (!pr[i]) {
            torol(i);
            int p=i;
            while(van(p)) p*=i, ans*=i;
        }
    }
    valasz(ans);
    return 0;
}