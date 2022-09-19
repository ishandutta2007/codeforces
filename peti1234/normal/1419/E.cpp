#include <bits/stdc++.h>

using namespace std;
int w, n, ut, k, p;
set<int> s;
int main()
{
    cin >> w;
    while(w--) {
        cin >> n, ut=n, k=0, p=0;
        for (int i=2; i*i<=n; i++) if (n%i==0) s.insert(i), s.insert(n/i), k+=(i*i==n/i);
        if (s.size()==2 && !k) cout << *(s.begin()) << " ", s.erase(*s.begin()), p=1;
        cout << ut << " ";
        while(s.size()>0) for (auto it=s.begin(); it!=s.end(); ++it) if (__gcd(ut, *it)!=1) {ut=*it, s.erase(ut), cout << ut << " "; break;}
        cout << "\n" << p << "\n";
    }
    return 0;
}