#include <bits/stdc++.h>

using namespace std;
const int c=500005;
int w, veg, n, t[c], ut[c];
vector<int> s, sz[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    sz[0].push_back(0);
    while(w--) {
        cin >> n;
        veg=0, s.clear(), s.push_back(0);
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            sz[i].clear();
            while(s.size()>1 && t[i]>=t[s.back()]) {
                s.pop_back();
            }
            ut[i]=s.back();
            //cout << "ert " << i << " " << ut[i] << "\n";
            s.push_back(i);
        }
        for (int i=1; i<=n; i++) {
            int lo=0, hi=veg+1, mid;
            while(hi-lo>1) {
                mid=(hi+lo)/2;
                if (t[sz[mid].back()]>t[i]) {
                    hi=mid;
                } else {
                    lo=mid;
                }
            }
            int pos=lo;
            sz[pos+1].push_back(i);
            veg=max(veg, pos+1);
            lo=-1, hi=sz[pos].size();
            while(hi-lo>1) {
                mid=(hi+lo)/2;
                if (t[sz[pos][mid]]<=t[i]) {
                    hi=mid;
                } else {
                    lo=mid;
                }
            }
            if (sz[pos][hi]<ut[i]) {
                veg=max(veg, pos+2);
                sz[pos+2].push_back(i);
            }
        }
        //cout << "valasz ";
        cout << veg << "\n";
    }
    return 0;
}
/*
1
2
2 1
*/