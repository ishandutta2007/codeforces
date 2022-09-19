#include <bits/stdc++.h>

using namespace std;
int n, t[502], p, w;
vector<int> sol;
void q(int a) {
    sol.push_back(a);
    swap(t[a+2], t[a]), swap(t[a+1], t[a+2]);
}
int main()
{
    cin >> w;
    while(w--) {
        cin >> n, sol.clear();
        for (int i=1; i<=n; i++) cin >> t[i];
        for (int i=1; i<=n-2; i++) {
            p=i;
            for (int j=i; j<=n; j++) if (t[j]<t[p]) p=j;
            if (p==n) p-=2, q(p);
            if ((p-i)%2) q(p-1), p++;
            while (p>i) p-=2, q(p);
        }
        if (t[n]<t[n-1]) for (int i=1; i<=n-2; i++) if (t[i]==t[i+1]) {
            for (int j=i; j<=n-2; j++) q(j), q(j);
            break;
        }
        if (t[n-2]==t[n]) q(n-2);
        if (t[n]<t[n-1]) cout << -1 << "\n";
        else {
            cout << sol.size() << "\n";
            for (int i=0; i<sol.size(); i++) cout << sol[i] << " ";
            cout << "\n";
        }
    }
    return 0;
}