#include <bits/stdc++.h>

using namespace std;
char c;
int t[7], e, v, k, x, ans;
vector<int> p;
int main()
{
    for (int i=1; i<=6; i++) {
        cin >> c, x=c-'0', t[i]=x;
        if (i<=3) e+=x;
        else v+=x;
    }
    k=abs(e-v);
    for (int i=1; i<=6; i++) {
        if (i<=3==e<v) p.push_back(9-t[i]);
        else p.push_back(t[i]);
    }
    sort(p.rbegin(), p.rend());
    while(k>0) k-=p[ans], ans++;
    cout << ans << "\n";
    return 0;
}