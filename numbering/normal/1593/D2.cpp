#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e18;
int gcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    if(a < b) swap(a, b);
    while(b) {
        a = a % b;
        swap(a, b);
    }
    return a;
}
typedef pair<int,int> P;
vector<int> A;
bool isCheck(int k) {
    vector<int> M;
    int i;
    for(i=0;i<A.size();i++) M.push_back(A[i]%k);
    sort(M.begin(),M.end());
    bool isTrue = false;
    for(i=0;i<A.size();i++) {
        int j = i;
        while(i+1<A.size()&&M[i+1]==M[i]) i++;
        if((i-j+1) >= (A.size()+1)/2) isTrue = true;
    }
    return isTrue;
}
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int N;
        A.clear();
        int a;
        int i;
        cin >> N;
        for(i=0;i<N;i++) {
            cin >> a;
            a += 1000005;
            A.push_back(a);
        }
        bool isSame = false;
        sort(A.begin(),A.end());
        for(i=0;i<N;i++) {
            int j = i;
            while(i+1<N&&A[i+1]==A[i]) i++;
            if((i-j+1) >= (N+1)/2) isSame = true;
        }
        if(isSame) {
            cout << "-1\n";
            continue;
        }
        int ans = 0;
        for(i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                if(A[i]<A[j]) {
                    int d = A[j] - A[i];
                    for(int k=1;k*k<=d;k++) {
                        if(d%k==0) {
                            if(isCheck(k)) ans = max(ans, k);
                            if(k*k!=d&&isCheck(d/k)) ans = max(ans, d/k);
                        }
                    }
                }
            }
        }
        cout << ans << '\n';
    }
}