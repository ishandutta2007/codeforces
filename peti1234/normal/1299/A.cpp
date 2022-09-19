#include <bits/stdc++.h>

using namespace std;
int n, maxi=0;
vector<int> v, sol, q;
int t[100001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        v.push_back(x), q.push_back(x);
    }
    for (long long i=(1<<29); i>=1; i/=2) {
        sol.clear();
        for (int j=0; j<n; j++) {
            if (v[j]>=i) sol.push_back(j), v[j]-=i;
        }
        if (sol.size()==1) t[sol[0]]+=i;
        sol.clear();
    }
    for (int i=0; i<n; i++) if (t[i]>t[maxi]) maxi=i;
    cout << q[maxi] << " ";
    for (int i=0; i<n; i++) if (i!=maxi) cout << q[i] << " ";
    return 0;
}