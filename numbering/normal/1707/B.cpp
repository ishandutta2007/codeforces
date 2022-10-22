#include <bits/stdc++.h>
#define int long long
using namespace std;
int A[100005];
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int N;
        cin >> N;
        map<int,int> M[2];
        int i;
        for(i=0;i<N;i++) {
            int a;
            cin >> a;
            M[0][a]++;
        }
        for(i=1;i<N;i++) {
            M[i%2].clear();
            auto it1 = M[(i+1)%2].begin();
            auto it2 = it1;
            it2++;
            int cnt= 0;
            for(;it2!=M[(i+1)%2].end();it1++,it2++) {
                M[i%2][it2->first-it1->first]++;
                cnt++;
            }
            if(cnt != N-i) M[i%2][0] = N-i-cnt;
        }
        cout << M[(N-1)%2].begin()->first << '\n';
    }
}