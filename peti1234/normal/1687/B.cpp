#include <bits/stdc++.h>

using namespace std;
const int c=505;
int n, m, ert[c], sum;
vector<pair<int, int> > sz;
bool v[c];
int kerd() {
    cout << "? ";
    for (int i=1; i<=m; i++) {
        cout << v[i];
    }
    cout.flush() << endl;
    int x;
    cin >> x;
    return x;
}
int main()
{
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        v[i]=1;
        sz.push_back({kerd(), i});
        v[i]=0;
    }
    sort(sz.begin(), sz.end());
    for (auto x:sz) {
        sum+=x.first;
        v[x.second]=1;
        if (kerd()!=sum) {
            v[x.second]=0;
            sum-=x.first;
        }
    }
    cout << "! " << sum << "\n";
    return 0;
}