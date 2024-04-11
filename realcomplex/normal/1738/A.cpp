#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
    fastIO;
    //freopen("in.txt", "r", stdin);
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0 ; i < n; i ++ ){
            cin >> a[i];
        }
        ll res = 0;
        int x;
        vector<int> aa, bb;
        for(int i = 0 ; i < n; i ++) {
            cin >> x;
            res += x;
            if(a[i] == 0) aa.push_back(x);
            else bb.push_back(x);
        }
        sort(aa.begin(), aa.end());
        sort(bb.begin(), bb.end());
        reverse(aa.begin(), aa.end());
        reverse(bb.begin(), bb.end());
        int m = min(aa.size(), bb.size());
        for(int i = 0 ; i < m ; i ++ ){
            res += aa[i];
            res += bb[i];
        }
        if(aa.size() == bb.size())
            res -= min(aa[m - 1], bb[m - 1]);
        cout << res << "\n";
    }
    return 0;
}