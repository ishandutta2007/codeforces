#include <bits/stdc++.h>

using namespace std;
bool test=0;
const int c=500005;
int w, n, db[c][2];
int lep=0;
set<int> regi, uj;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    if (!test) cin >> w;
    else w=1;
    while (w--) {
        if (!test) cin >> n;
        else n=1000;
        for (int i=1; i<=n; i++) {
            int x;
            if (!test) cin >> x;
            else x=rand()+1;
            regi.insert(x);
            db[x][0]++;
        }
        bool par=0;
        for (int i=1; i<n; i++) {
            //cout << "alap " << regi.size() << " " << uj.size() << "\n";
            int ut=-1;
            for (auto x:regi) {
                lep++;
                int cnt=db[x][par];
                if (cnt>1) {
                    uj.insert(0);
                    db[0][1-par]+=cnt-1;
                }
                if (ut!=-1) {
                    uj.insert(x-ut);
                    db[x-ut][1-par]++;
                }
                ut=x;
            }
            swap(regi, uj);
            for (auto x:uj) {
                db[x][par]=0;
            }
            par=1-par;
            uj.clear();
        }
        int x=(*regi.begin());
        cout << x << "\n";
        db[x][par]=0;
        regi.clear();
        //cout << "lep " << lep << "\n";
    }
    return 0;
}
/*
1
2
1 2
*/