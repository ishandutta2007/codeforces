#include <bits/stdc++.h>
#define int long long
using namespace std;
int Qu(string s) {
    cout << "? " << s << endl;
    int c;
    cin >> c;
    return c;
}
int val[505];
signed main() {
    /*cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);*/
    int N, M;
    cin >> N >> M;
    int i, j;
    for(i=0;i<M;i++) {
        string s="";
        s.resize(M);
        for(j=0;j<M;j++) {
            if(i==j) s[j]='1';
            else s[j]='0';
        }
        val[i] = Qu(s);
    }
    vector<int> V;
    for(i=0;i<M;i++) V.push_back(i);
    sort(V.begin(),V.end(),[&](int x, int y) {
         return val[x] < val[y];
         });
    string ans="";
    ans.resize(M);
    for(i=0;i<M;i++) ans[i] = '0';
    int cnt = 0;
    for(i=0;i<M;i++) {
        string s = ans;
        s[V[i]]='1';
        int c = Qu(s);
        if(c-cnt==val[V[i]]) {
            cnt = c;
            ans = s;
        }
    }
    cout << "! " << cnt << endl;
}