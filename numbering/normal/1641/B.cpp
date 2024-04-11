#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> P;
vector<P> ans;
vector<int> res;
void solve(vector<int> A, int len) {
    if(A.size()==0) return;
    int i, j;
    int c = A[0];
    for(i=1;i<A.size();i++) {
        if(A[i]==c) break;
    }
    if(i==1) {
        res.push_back(2);
        vector<int> A2;
        for(i=2;i<A.size();i++) A2.push_back(A[i]);
        solve(A2, len+2);
        return;
    }
    int pos = i;
    for(i=1;i<pos;i++) {
        ans.push_back(P(pos+i+len,A[i]));
    }
    res.push_back(2*pos);
    vector<int> A2;
    for(i=pos-1;i>=1;i--) A2.push_back(A[i]);
    for(i=pos+1;i<A.size();i++) A2.push_back(A[i]);
    solve(A2, len+2*pos);
}
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int N;
        cin >> N;
        vector<int> A;
        ans.clear();
        res.clear();
        int i;
        map<int,int> M;
        for(i=0;i<N;i++) {
            int a;
            cin >> a;
            A.push_back(a);
            M[a]++;
        }
        bool isPos = true;
        for(auto it = M.begin();it!=M.end();it++) {
            if(it->second%2!=0) isPos = false;
        }
        if(!isPos) {
            cout << "-1\n";
            continue;
        }
        solve(A, 0);
        cout << ans.size() << '\n';
        for(i=0;i<ans.size();i++) cout << ans[i].first << ' ' << ans[i].second << '\n';
        cout << res.size() << '\n';
        for(i=0;i<res.size();i++) cout <<res[i] <<' ';
        cout << '\n';
    }
}