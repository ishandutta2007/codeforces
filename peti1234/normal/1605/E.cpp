#include <bits/stdc++.h>

using namespace std;
const int c=1000005;
long long n, m, a[c], b[c], mob[c], ans[c], sum, rossz, jo;
priority_queue<int> q;
vector<pair<int, int> > sz;
int main()
{
    ios_base::sync_with_stdio(false);
    mob[1]=1;
    for (int i=1; i<c; i++) {
        for (int j=2*i; j<c; j+=i) mob[j]-=mob[i];
        //if (i<=10) cout << mob[i] << " ";
    }
    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<=n; i++) cin >> b[i];
    b[1]=0;
    for (int i=1; i<=n; i++) {
        long long ert=b[i]-a[i];
        for (int j=i; j<=n; j+=i) a[j]+=ert;
        //cout << i << " " << ert << "\n";
        sum+=abs(ert);
        if (mob[i]==1) {
            if (ert>=0) rossz++;
            else q.push(ert), jo++;
        }
        if (mob[i]==-1) {
            if (ert<=0) rossz++;
            else q.push(-ert), jo++;
        }
    }
    cin >> m;
    for (int i=1; i<=m; i++) {
        int x;
        cin >> x;
        sz.push_back({x, i});
    }
    sort(sz.begin(), sz.end());
    for (auto p:sz) {
        long long x=p.first;
        while (q.size()>0 && x>=-q.top()) {
            sum+=2*q.top();
            jo--;
            q.pop(), rossz++;
        }
        ans[p.second]=sum+(rossz-jo)*x;
    }
    for (int i=1; i<=m; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}
/*
6
2 5 4 1 3 6
-1 4 6 2 3 5
3
1
8
4
*/