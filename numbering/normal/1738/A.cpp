#include <bits/stdc++.h>
#define int long long
using namespace std;
int A[100005];
int B[100005];
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int i, j;
        int N;
        cin >> N;
        vector<int> V1, V2;
        for(i=0;i<N;i++) {
            cin >> A[i];
        }
        int sum = 0;
        for(i=0;i<N;i++) {
            cin >>B[i];
            if(A[i]==0) V1.push_back(B[i]);
            else V2.push_back(B[i]);
            sum += B[i];
        }
        int dob = min((int)V1.size(), (int)V2.size());
        sort(V1.begin(),V1.end());
        sort(V2.begin(),V2.end());
        reverse(V1.begin(),V1.end());
        reverse(V2.begin(),V2.end());
        for(i=0;i<dob;i++) sum += V1[i];
        for(i=0;i<dob;i++) sum += V2[i];
        if(V1.size()==V2.size()&&dob>0) sum -= min(V1[dob-1], V2[dob-1]);
        cout << sum << '\n';
    }
}