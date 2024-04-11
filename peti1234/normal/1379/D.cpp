#include <bits/stdc++.h>

using namespace std;
int n, m, k, t[100002], mini=1e9, pos, sum, si;
vector<pair<int, int> > p;
void add(int a, int b) {p.push_back({a, b});}
int main()
{
    cin >> n >> m >> m >> k, m/=2;
    add(2e9, 0);
    for (int i=1; i<=n; i++) {
        cin >> t[i] >> t[i], t[i]+=k;
        int x=t[i]%m, y=(t[i]+m+1-k)%m;
        add(y, 1), add(x, -1);
        if (y>x) add(0, 1);
    }
    sort(p.begin(), p.end()), si=p.size();
    for (int i=0; i<si; i++) {
        int fi=p[i].first, se=p[i].second;
        sum+=se;
        if (i+1<si && fi!=p[i+1].first && sum<mini) mini=sum, pos=fi;
    }
    cout << mini << " " << pos << "\n";
    for (int i=1; i<=n; i++) {
        int x=t[i]%m, y=(t[i]+m-k)%m;
        if (pos!=x && pos!=y && (y<x && pos>y && pos<x) || (y>x && (pos>y || pos<x))) cout << i << " ";
    }
    return 0;
}