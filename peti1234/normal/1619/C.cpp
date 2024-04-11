#include <bits/stdc++.h>

using namespace std;
int w;
string a, b;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> a >> b;
        vector<int> res;
        int sa=a.size(), sb=b.size();
        bool baj=0;
        while (sa>0 && sb>0) {
            int x=a[sa-1]-'0', y=b[sb-1]-'0';
            if (y>=x) {
                res.push_back(y-x);
                sa--, sb--, a.pop_back(), b.pop_back();
            } else {
                if (sb==1 || b[sb-2]!='1') {
                    baj=1;
                    break;
                } else {
                    res.push_back(y+10-x);
                    sa--, sb-=2, a.pop_back(), b.pop_back(), b.pop_back();
                }
            }
        }
        while (sb>0) {
            int y=b[sb-1]-'0';
            res.push_back(y);
            sb--;
            b.pop_back();
        }
        if (a.size()>0) {
            baj=1;
        }
        if (baj) {
            cout << -1 << "\n";
        } else {
            while (res.size()>0 && res.back()==0) {
                res.pop_back();
            }
            reverse(res.begin(), res.end());
            for (auto x:res) {
                cout << x;
            }
            cout << "\n";
        }
    }
    return 0;
}
/*
1
1 20
*/