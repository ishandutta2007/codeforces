#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e18;
int A[200005];
int get_ans(int N, int k) {
    vector<int> B;
    int i;
    for(i=0;i<N;i++) B.push_back(A[i]+k);
    int sum = 0;
    sum += B[0] * B[N-1];
    for(i=1;i+1<N;i++) {
        if(B[i]<=0) sum += B[i] * B[N-1];
        else sum += B[0] * B[i];
    }
    return sum - k*k * (N-1);
}
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int N;
        int i, j;
        cin >> N;
        for(i=0;i<N;i++) cin >>A[i];
        int sum = 0;
        for(i=0;i<N;i++) sum += A[i];
        if(N==2) {
            if(A[0]+A[1]!=0) cout << "INF\n";
            else cout << A[0]*A[1] << '\n';
            continue;
        }
        sort(A, A+N);
        if(sum+(N-2)*A[0]>0 || sum + (N-2) * A[N-1] < 0) {
            cout << "INF\n";
            continue;
        }
        int s = -INF, e = INF;
        while(e-s>=3) {
            int mid = (s + e) / 2;
            int v1 = get_ans(N, mid);
            int v2 = get_ans(N, mid+1);
            if(v1<v2) s = mid;
            else e = mid;
        }
        int ma = -INF;
        for(i=s;i<=e;i++) ma = max(ma, get_ans(N, i));
        cout << ma << '\n';
    }
}