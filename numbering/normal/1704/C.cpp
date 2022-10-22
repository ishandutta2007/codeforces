#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e18;
int A[200005];
int B[200005];
typedef pair<int,int> P;
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int i, j;
        int N, M;
        cin >> N >> M;
        for(i=0;i<M;i++) cin >> A[i];
        sort(A, A+M);
        for(i=0;i+1<M;i++) B[i] = A[i+1] - A[i]-1;
        B[M-1] = A[0] - A[M-1] + N - 1;
        set<P> S1, S2;
        for(i=0;i<M;i++) S1.insert(P(B[i],i));
        int cnt = 0;
        int ans = 0;
        int cnt2 = M;
        while(S1.size()) {
            P k = *S1.rbegin();
            if(k.first - 2*cnt <= 2) {
                cnt2 += max(k.first - cnt - 1,0LL);
                cnt++;
            }
            else {
                cnt+= 2;
            }
            S1.erase(k);
            auto it = S1.begin();
            while(it!=S1.end()) {
                if(it->first>2*cnt) break;
                cnt2 += it->first;
                auto it2 = it;
                it++;
                S1.erase(it2);
            }
        }
        //cout << cnt2 << ' ' << cnt << '\n';
        cout << cnt2 + cnt * (cnt-1) / 2 << '\n';
    }
}