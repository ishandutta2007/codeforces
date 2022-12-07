#include <bits/stdc++.h>

using namespace std;

int main(){
    int ntest; cin >> ntest;
    while(ntest--) {
        int n; cin >> n;
        
        int last = -1;
        set<int> avail;
        for(int i = 1; i <= n; ++i) avail.insert(i);
        vector<int> ans(n), tomax(n);

        for(int i = 0; i < n; ++i) {
            int x; cin >> x;
            if (x != last) tomax[i] = x, ans[i] = x;
            last = x;
            tomax[i] = x;
            avail.erase(x);
        }


        tomax[n-1] = n;
        for(int i = n - 2; i >= 0; --i) {
            if(tomax[i] == 0) tomax[i] = tomax[i+1];
        }

        vector<int> ansmin = ans, ansmax = ans;
        
        set<int> cur = avail;
        for(int i = 0; i < n; ++i) {
            if (ansmin[i] == 0) {
                ansmin[i] = *cur.begin();
                cur.erase(cur.begin());
            }   
        }

        cur = avail;
        for(int i = 0; i < n; ++i) {
            if (ansmax[i] == 0) {
                auto it = cur.lower_bound(tomax[i]);
                --it;
                ansmax[i] = *it;
                cur.erase(ansmax[i]);

            }
        }

        for(int i = 0; i < n; ++i) cout << ansmin[i] << " "; cout << endl;
        for(int i = 0; i < n; ++i) cout << ansmax[i] << " "; cout << endl;

    }
    return 0;
}