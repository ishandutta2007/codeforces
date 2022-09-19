#include <bits/stdc++.h>

using namespace std;
const int c=500005;
long long n, t[c], le[c], fel[c], pos, cnt;
vector<int> kis, nagy;
void solve() {
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    kis.push_back(n+1), nagy.push_back(n+1);
    for (int i=n; i>=1; i--) {
        while (kis.back()!=n+1 && t[i]<t[kis.back()]) {
            kis.pop_back();
        }
        le[i]=kis.back();
        while (nagy.back()!=n+1 && t[i]>t[nagy.back()]) {
            nagy.pop_back();
        }
        fel[i]=nagy.back();
        nagy.push_back(i), kis.push_back(i);
    }
    /*for (int i=1; i<=n; i++) {
        cout << i << " " << le[i] << " " << fel[i] << "\n";
    }
    cout << "vege\n";
    return;*/
    pos=1, cnt=0;
    while (pos<n) {
        int id=(t[pos]<t[pos+1] ? 1 : 0);
        int kov=(id ? le[pos] : fel[pos]), s=(id ? fel[pos] : le[pos]);
        //cout << "fontos " << id << " " << kov << " " << s << "\n";
        while (s<kov) {
            pos=s;
            s=(id ? fel[pos] : le[pos]);
        }
        cnt++;
    }

    //cout << "valasz: ";
    cout << cnt << "\n";


    pos=0, cnt=0;
    for (int i=1; i<=n; i++) {
        t[i]=0, le[i]=0, fel[i]=0;
    }
    kis.clear(), nagy.clear();
}
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        solve();
    }
    return 0;
}
/*
1
2
1 2
*/