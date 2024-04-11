#include <bits/stdc++.h>
#define int long long
using namespace std;
int A[200005];
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int N;
        cin >> N;
        int i, j;
        for(i=0;i<N;i++) cin >> A[i];
        int sum = 0;
        for(i=0;i<N;i++) {
            sum += A[i];
        }
        if(sum != 0){
            cout << "No\n";
            continue;
        }
        bool isPos = true;
        bool isEnd = false;
        for(i=0;i+1<N;i++) {
            if(A[i]==0) isEnd = true;
            if(A[i]<0) isPos = false;
            if(A[i]>0&&isEnd) isPos = false;
            A[i+1] += A[i];
        }
        cout << (isPos ? "Yes\n" : "No\n" );
    }
}