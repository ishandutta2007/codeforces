#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int main() {
    int n,k;
    cin >> n >> k;
    vector<int> a;
    int res, A[3], B[3];
    cout << "and 2 3" << endl;
    cin >> A[0];
    cout << "and 1 3" << endl;
    cin >> A[1];
    cout << "and 1 2" << endl;
    cin >> A[2];
    cout << "or 2 3" << endl;
    cin >> B[0];
    cout << "or 1 3" << endl;
    cin >> B[1];
    cout << "or 1 2" << endl;
    cin >> B[2];
    int C[3] = {0,0,0};
    for(int i = 31; i >= 0; i--) {
        if(((A[0]|A[1]|A[2])&(1<<i)) == 0) {
            if(B[0]&B[1]&(1<<i)) C[2] |= (1<<i);
            if(B[0]&B[2]&(1<<i)) C[1] |= (1<<i);
            if(B[1]&B[2]&(1<<i)) C[0] |= (1<<i);
            continue;
        }
        if(((A[0]&A[1]&A[2])&(1<<i))){
            C[0] |= (1<<i);
            C[1] |= (1<<i);
            C[2] |= (1<<i);
            continue;
        }
        C[0] |= (1<<i);
        C[1] |= (1<<i);
        C[2] |= (1<<i);
        for(int j = 0; j < 3; j++) {
            if(A[j]&(1<<i)) {
                C[j] ^= (1<<i);
            }
        }
    }
    a.push_back(C[0]);
    a.push_back(C[1]);
    a.push_back(C[2]);
    for(int i = 3; i < n; i++) {
        cout << "and 1 " << i+1 << endl;
        int AND;
        cin >> AND;
        cout << "or 1 " << i+1 << endl;
        int OR;
        cin >> OR;
        int x = 0;
        for(int i = 31; i >= 0; i--) {
            if(a[0]&(1<<i)) {
                if(AND&(1<<i)) x |= (1<<i);
            }
            else {
                if(OR&(1<<i)) x |= (1<<i);
            }
        }
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    cout << "finish " << a[k-1] << endl;
    return 0;
}