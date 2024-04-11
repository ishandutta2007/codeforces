#include <bits/stdc++.h>

using namespace std;
int n, m, d;
vector<pair<int, int> > t;
vector<pair<int, int> > s;
int el=-INT_MAX;
int maxi=0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> d;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        t.push_back({x, i});
    }
    sort(t.begin(), t.end());
    /*for (int i=0; i<t.size(); i++) {
        int y=t[i].second;
        int x=t[i].first;
        if (x>el+d) {
            el=x;
            s.push_back({y, 1});
        } else {
            s.push_back({y, s.back().second+1});
            maxi=max(maxi, s.back().second);
        }
    }*/
    int x=0, y=0;
    while(y<n) {
        if (t[y].first-t[x].first<=d) {
            maxi=max(maxi, y-x);
            y++;
        } else {
            x++;
        }
    }
    maxi++;
    for (int i=0; i<t.size(); i++) {
        s.push_back({t[i].second, (i+1)%maxi});
    }
    sort(s.begin(), s.end());
    cout << maxi << endl;
    for (int i=0; i<s.size(); i++) {
        if (s[i].second==0) {
            s[i].second+=maxi;
        }
        cout << s[i].second << " ";
    }
    return 0;
}