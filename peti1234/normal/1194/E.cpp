#include <bits/stdc++.h>
 
using namespace std;
int n;
int k=5001;
int p=16384;
int kom[35001];
int s[35001];
int f[35001];
long long sum;
vector<pair<int, pair<int, int> > > v;
vector<pair<int, pair<int, int> > > fu;
void pb(int a)
{
    if (a==0) {
        return;
    }
    kom[a]++;
    pb(a/2);
}
int ask(int a, int st, int fi)
{
    if (st>f[a] || fi<s[a]) {
        return 0;
    }
    if (st<=s[a] && f[a]<=fi) {
        return kom[a];
    }
    return ask(2*a, st, fi)+ask(2*a+1, st, fi);
}
void solve(int a)
{
    int t=v[a].first;
    int ke=v[a].second.first;
    int ve=v[a].second.second;
    vector<pair<int, int> >jo;
    for (int i=0; i<fu.size(); i++) {
        int a=fu[i].first;
        int b=fu[i].second.first;
        int c=fu[i].second.second;
        if (ke<=a && a<=ve && b<=t && t<=c) {
            jo.push_back({c, a});
        }
    }
    int x=0;
    sort(jo.rbegin(), jo.rend());
    long long ans=0;
    for (int i=v.size()-1; i>a; i--) {
        int fi=v[i].first;
        int sefi=v[i].second.first;
        int sese=v[i].second.second;
        while(x<jo.size() && jo[x].first>=fi) {
            pb(jo[x].second+p-1);
            x++;
        }
        long long r=ask(1, sefi+p-1, sese+p-1);
        ans+=r*(r-1)/2;
    }
    sum+=ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a>c) {
            swap(a, c);
        }
        if (b>d) {
            swap(b, d);
        }
        a+=k, b+=k, c+=k, d+=k;
        if (a==c) {
            v.push_back({a, {b, d}});
        } else {
            fu.push_back({b, {a, c}});
        }
    }
    sort(v.begin(), v.end());
    for (int i=p; i<2*p; i++) {
        s[i]=i;
        f[i]=i;
    }
    for (int i=p-1; i>=1; i--) {
        s[i]=s[2*i];
        f[i]=f[2*i+1];
    }
    for (int i=0; i<v.size(); i++) {
        for (int i=1; i<=2*p; i++) {
            kom[i]=0;
        }
        solve(i);
    }
    cout << sum << endl;
    return 0;
}