#include <bits/stdc++.h>

using namespace std;
int n;
int t[100001];
vector<pair<int, int > > k;
long long p;
int m;
int l;
int h;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        t[i]=x;
        k.push_back({i-x-1, i});
    }
    sort(k.begin(), k.end());
    for (int i=1; i<=n; i++) {
        while(l<k.size() && k[l].second<=i) {
            l++;
        }
        if (t[i]==m || (k[l].first==h && k[l].second>i)) {
            p+=m-t[i];
            m++;
        } else {
            h++;
            p+=m-t[i]-1;
        }
    }
    cout << p << endl;
    return 0;
}