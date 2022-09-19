#include <bits/stdc++.h>

using namespace std;
int n, m, ki[55];
vector<pair<int, pair<int, int> > > el;
vector<pair<pair<int, int>, int> > sz;
set<int> s;
map<int, pair<long long, long long> > s2;
long long sum, nagy, ans;
int holvan(int a) {
    return (ki[a] ? ki[a]=holvan(ki[a]) : a);
}
void unio(int a, int b) {
    a=holvan(a), b=holvan(b);
    if (a!=b) {
        ki[a]=b;
    }
}

void calc(long long x) {
    auto it=s.upper_bound(x);
    it--;
    long long sum=s2[*it].first, nagy=s2[*it].second;
    long long ert=sum+(n-1-2*nagy)*x;
    ans=ans^ert;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        el.push_back({c, {a, b}});
    }
    sort(el.begin(), el.end());
    for (int i=0; i<m; i++) {
        int aa=el[i].second.first, bb=el[i].second.second, ert=el[i].first;
        bool jo=0;
        for (int j=i-1; j>=0; j--) {
            unio(el[j].second.first, el[j].second.second);
            if (holvan(aa)==holvan(bb)) {
                int s=ert+el[j].first;
                sz.push_back({{(s+1)/2, 1}, s});
                jo=1;
                break;
            }
        }
        sz.push_back({{ert, -1}, -2*ert});
        for (int i=1; i<=n; i++) {
            ki[i]=0;
        }
        if (!jo) {
            sum+=ert;
        }
    }
    s.insert(-1);
    nagy=n-1;
    s2[-1]={sum, nagy};
    sort(sz.begin(), sz.end());
    for (auto x:sz) {
        long long a=x.second, b=x.first.second;
        if (b!=0) {
            sum+=a;
            nagy+=b;
            int ert=x.first.first;
            s.insert(ert);
            s2[ert]={sum, nagy};
        }
        if (b==0) {
            long long ert=sum+(n-1-2*nagy)*a;
            ans=ans^ert;
        }
    }
    long long p, k, a, b, c, x;
    cin >> p >> k >> a >> b >> c;
    for (int i=1; i<=p; i++) {
        cin >> x;
        calc(x);
    }
    for (int i=p+1; i<=k; i++) {
        x=(x*a+b)%c;
        calc(x);
    }
    cout << ans << "\n";
    return 0;
}