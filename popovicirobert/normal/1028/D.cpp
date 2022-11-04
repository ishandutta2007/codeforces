#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MOD = (int) 1e9 + 7;

inline void mod(int &x) {
    if(x >= MOD)
        x -= MOD;
}

set <int> mst, mst1, mst2;
set <int> :: iterator it;

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int n;
    ios::sync_with_stdio(false);
    cin >> n;
    int ans = 1;
    while(n > 0) {
        n--;
        string str;
        int x;
        cin >> str >> x;
        if(str == "ADD") {
            if(!mst1.empty() && *prev(mst1.end()) > x) {
                mst1.insert(x);
            }
            else if(!mst2.empty() && *mst2.begin() < x) {
                mst2.insert(x);
            }
            else {
                mst.insert(x);
            }
        }
        else {
            if(!mst1.empty() && *prev(mst1.end()) == x) {
                mst1.erase(prev(mst1.end()));
                for(auto it : mst) {
                    mst2.insert(it);
                }
                mst.clear();
            }
            else if(!mst2.empty() && *mst2.begin() == x) {
                mst2.erase(mst2.begin());
                for(auto it : mst) {
                    mst1.insert(it);
                }
                mst.clear();
            }
            else if(mst.find(x) != mst.end()) {
                ans *= 2;
                mod(ans);
                for(auto it : mst) {
                    if(it < x)
                        mst1.insert(it);
                    if(it > x)
                        mst2.insert(it);
                }
                mst.clear();
            }
            else {
                cout << 0;
                return 0;
            }
        }
    }
    ans = (1LL * ans * (mst.size() + 1)) % MOD;
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}