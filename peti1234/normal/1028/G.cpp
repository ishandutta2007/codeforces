#include <bits/stdc++.h>

using namespace std;
vector<long long> sz{(long long)204761410474, 2046, 6, 2, 1};
vector<long long> sol;
long long lo=1, k=1e4, h[4], x, p, ert;
int main()
{
    h[0]=1;
    for (int i=1; i<=3; i++) h[i]=h[i-1]*(k+1);
    while(p<5) {
        if (p>=3) {
            ert=lo;
            if (p==4) ert--;
            for (int i=1; i<=min(k, lo); i++) {
                if (p==3) ert+=min(ert, k);
                else ert++;
                sol.push_back(ert);
                if (p==3) ert++;
            }
        }
        else {
            if (lo==1) sol.push_back(sz[p]);
            else {
                ert=lo-1;
                if (lo==2047) ert=20468427-h[2];
                for (int i=1; i<=min(k, lo); i++) {
                    ert+=h[4-p];
                    sol.push_back(ert);
                }
            }
        }
        cout << sol.size() << " ";
        for (int i=0; i<sol.size(); i++) cout << sol[i] << " ";
        cout.flush() << "\n";
        cin >> x;
        if (x==-1) {
            return 0;
        }
        if (x) lo=sol[x-1]+1;
        p++;
        sol.clear();
    }
    return 0;
}
// Lehetett volna szpen is csinlni.