#include <bits/stdc++.h>

using namespace std;
int w, n, t[1002], db[1002], cnt, mex;
vector<int> sol;
void calc() {
    mex=0;
    while (db[mex]) {
        mex++;
    }
}
void valt(int a) {
    db[t[a]]--;
    db[mex]++;
    t[a]=mex;
    if (a==mex) {
        cnt++;
    }
    sol.push_back(a+1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=0; i<=n; i++) {
            db[i]=0;
        }
        cnt=0;
        sol.clear();
        for (int i=0; i<n; i++) {
            cin >> t[i];
            if (t[i]==i) {
                cnt++;
            }
            db[t[i]]++;
        }
        while (cnt<n) {
            calc();
            if (mex==n) {
                for (int i=0; i<n; i++) {
                    if (t[i]!=i) {
                        valt(i);
                        break;
                    }
                }
            } else {
                valt(mex);
            }
        }
        cout << sol.size() << "\n";
        for (int i:sol) {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}