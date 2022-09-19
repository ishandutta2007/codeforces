#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int w, n, k, pos[c], a[c], b[c], el[c], kov[c];
long long sum, mod=998244353;
bool v[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> k, v[0]=1, a[n+1]=0, v[n+1]=1, el[n+1]=0, sum=1;
        for (int i=1; i<=n; i++) {
            cin >> a[i];
            v[i]=0;
            pos[a[i]]=i, el[i]=i-1, kov[i]=i+1;
        }
        for (int i=1; i<=k; i++) {
            cin >> b[i];
            v[b[i]]=1;
        }
        for (int i=1; i<=k; i++) {
            int db=0, x=pos[b[i]];
            db+=1-v[a[el[x]]];
            db+=1-v[a[kov[x]]];
            kov[el[x]]=kov[x];
            el[kov[x]]=el[x];
            sum*=db, sum%=mod;
        }
        cout << sum << "\n";
    }
    return 0;
}
/*
1
7 4
1 4 7 3 6 2 5
3 2 4 5
*/