#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 2e5;

vector <int> sol[MAXN + 1];

string str;

multiset <int> mst[2];
multiset <int> :: iterator it;

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int n;
    ios::sync_with_stdio(false);
    cin >> str;
    n = str.size();
    for(int i = 0; i < n; i++) {
        if(str[i] == '0')
            mst[0].insert(i + 1);
        else
            mst[1].insert(i + 1);
    }
    int cnt = 0;
    while(1) {
        if(mst[0].size() == 0) {
            if(mst[1].size() > 0) {
                cout << -1;
                return 0;
            }
            break;
        }
        cnt++;
        int pos = *mst[0].begin();
        sol[cnt].push_back(pos);
        mst[0].erase(mst[0].begin());
        while(1) {
            it = mst[1].upper_bound(pos);
            if(it == mst[1].end()) {
                break;
            }
            pos = *it;
            sol[cnt].push_back(pos);
            mst[1].erase(it);
            it = mst[0].upper_bound(pos);
            if(it == mst[0].end()) {
                cout << -1;
                return 0;
            }
            sol[cnt].push_back(*it);
            pos = *it;
            mst[0].erase(it);
        }
    }
    cout << cnt << "\n";
    for(int i = 1; i <= cnt; i++) {
        sort(sol[i].begin(), sol[i].end());
        cout << sol[i].size() << " ";
        for(auto it : sol[i]) {
            cout << it << " ";
        }
        cout << "\n";
    }
    //cin.close();
    //cout.close();
    return 0;
}