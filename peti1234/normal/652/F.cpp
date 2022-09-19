#include <bits/stdc++.h>

using namespace std;
const int c=300005;
long long n, m, k, db, ans[c], sum, kor, ert;
vector<long long> kezd, veg;
map<int, int> s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i=1; i<=n; i++) {
        int pos;
        char c;
        cin >> pos >> c;
        pos%=m;
        kezd.push_back(pos);
        s[pos]=i;
        int p=(c=='L' ? -1 : 1);
        veg.push_back(((pos+p*k)%m+m)%m);
        sum+=pos-veg.back();
        db+=p;
    }
    sort(kezd.begin(), kezd.end()), sort(veg.begin(), veg.end());
    kor+=k/m*db;
    sum+=k%m*db;
    kor+=sum/m;

    ert=(kor%n+n)%n;
    for (int i=0; i<n; i++) {
        ans[s[kezd[i]]]=veg[(i+ert)%n];
    }
    for (int i=1; i<=n; i++) {
        if (!ans[i]) ans[i]=m;
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}