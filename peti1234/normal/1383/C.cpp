#include <bits/stdc++.h>

using namespace std;
#define rep(n) for(int i=0; i<n; i++)
const int n=20, p=1048576;
int w, k, mask[p], hv[n], db, maxi, r[p];
string a, b;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> k >> a >> b, db=0, maxi=0;
        rep(p) mask[i]=0, r[i]=0;
        rep(n) hv[i]=-1;
        rep(k) {
            int x=a[i]-'a', y=b[i]-'a';
            if (x!=y) mask[(1<<x)]=mask[(1<<x)]|(1<<y);
            while(hv[x]!=-1) x=hv[x];
            while(hv[y]!=-1) y=hv[y];
            if (x!=y) db++, hv[x]=y;
        }
        rep(p) {
            if (!i) continue;
            if ((i|mask[i])==mask[i]) r[i]=1;
            for (int j=0; j<n; j++) {
                int q=i|(1<<j);
                mask[q]=mask[q]|mask[i];
                if (r[i]) r[q]=1;
            }

            if (!r[i]) maxi=max(maxi, __builtin_popcount(i));
        }
        cout << n+db-maxi << "\n";
    }
    return 0;
}