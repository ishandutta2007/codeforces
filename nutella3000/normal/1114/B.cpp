#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n,m,k;
    cin >> n >> m >> k;
    int a[n];
    pair<int,int> b[n];
    ll f = 0;
    for(int i = 0;i < n;i++) {
        cin >> a[i];
        b[i].first = a[i];
        b[i].second = i;
        f += a[i];
    }
    sort(b,b + n);
    vector<int> index;
    for(int i = 0;i < n - k * m;i++) {
        index.push_back(b[i].second);
        f -= b[i].first;
    }
    sort(index.begin(),index.end());
    cout << f << '\n';
    int ind = 0;
    int j = 0;
    for(int i = 0;i < n;i++) {
        i += m - 1;
        while(ind < index.size() && index[ind] <= i) {
            i++;
            ind++;
        }
        if (j == k - 1) return 0;
        cout << i + 1 << " ";
        j++;
    }
}