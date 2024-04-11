#include <bits/stdc++.h>

using namespace std;
int k[500001];
int t[500002];
int maxi=0;
vector<int> q;
vector<int> w;
int c=-1;
int n, m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    t[n+1]=m;
    for (int i=1; i<=n+1; i++) {
        int x;
        x=t[i];
        if (x!=m) {
            if (k[x]==0) {
                q.push_back(x);
            }
            k[x]++;
        } else {
            c++;
            for (int j=0; j<q.size(); j++) {

                maxi=max(maxi, k[q[j]]);
                k[q[j]]--;
            }
            for (int i=0; i<q.size(); i++) {
                if (k[q[i]]>0) {
                    w.push_back(q[i]);
                }
            }
            q.clear();
            for (int i=0; i<w.size(); i++) {
                q.push_back(w[i]);
            }
            w.clear();
        }
    }

    cout << c+maxi << endl;
    return 0;
}