#include <bits/stdc++.h>

using namespace std;
int n;
int t[100001];
int v[100001];
vector<int> sz[100001];
int k[100001];
int q=1;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        sz[n-1-t[i]].push_back(i);
    }
    for (int i=0; i<n; i++) {
        if (sz[i].size()>0 && (sz[i].size()%(i+1))!=0) {
            cout << "Impossible" << endl;
            return 0;
        }
        if (sz[i].size()>0) {
            int x=i+1;
            for (int j=0; j<sz[i].size(); j++) {
                k[sz[i][j]]=q;
                if ((j+1)%x==0) {
                    q++;
                }
            }
        }
    }
    cout << "Possible" << endl;
    for (int i=1; i<=n; i++) {
        cout << k[i] << " ";
    }
    return 0;
}