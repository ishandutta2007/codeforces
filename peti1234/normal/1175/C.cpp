#include <bits/stdc++.h>
 
using namespace std;
vector<int> q;
int t;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> t;
    for (int i=1; i<=t; i++) {
        int ans=0;
        int opt=INT_MAX;
        q.clear();
        int n, k;
        cin >> n >> k;
        for (int i=0; i<k; i++) {
            int a;
            cin >> a;
            q.push_back(a);
        }
        for (int i=k; i<n; i++) {
            int a;
            cin >> a;
            q.push_back(a);
            if (a-q[i-k]<opt) {
                opt=a-q[i-k];
                ans=(a+q[i-k])/2;
            }
        }
 
        cout << ans << "\n";
    }
    return 0;
}