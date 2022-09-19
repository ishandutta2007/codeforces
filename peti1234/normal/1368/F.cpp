#include <bits/stdc++.h>

using namespace std;
int n, p=1, maxi, db, f;
bool v[1002];
vector<int> sz, kerd;
int main()
{
    cin >> n;
    for (int i=2; i<=n; i++) {
        int x=n/i*(i-1)+n%i-i;
        if (n%i==0) x++;
        if (x>maxi) maxi=x, p=i;
    }
    for (int i=1; i<=n; i++) if (i%p && i!=n) sz.push_back(i);
    while(db<maxi) {
        int si=0; kerd.clear();
        for (int i=0; i<sz.size(); i++) if(!v[sz[i]] && si<p) kerd.push_back(sz[i]), si++;
        cout << si << " ";
        for (int i=0; i<si; i++) cout << kerd[i] << " ", v[kerd[i]]=1, db++;
        cout.flush() << "\n";
        cin >> f;
        for (int i=1; i<=si; i++) db-=v[f], v[f]=0, f%=n, f++;
    }
    cout << 0 << endl;
    return 0;
}