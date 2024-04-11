#include <bits/stdc++.h>
#define endl '\n'
#define inf 1000000000000000001ll
#define lcm my_lcm
#define gcd my_gcd
typedef long long ll;
using namespace std;
int n,m,k,t;
int a[300001];
int l[300001];
int r[300001];
int d[300001];
bool ok(int x){
 
    vector<pair<int,int> >v;
    for (int i=1;i<=k;i++){
        if (d[i]<=x) continue;
        v.push_back({l[i],r[i]});
    }
    int time=m+1;
    sort(v.begin(),v.end());
    vector<pair<int,int> >u;
    if (v.empty()) return true;
    int L=v[0].first;
    int R=v[0].second;
    for (int i=1;i<v.size();i++){
        if (R<v[i].first){
            u.push_back({L,R});
            L=v[i].first;
            R=v[i].second;
        } else R=max(R,v[i].second);
    }
    u.push_back({L,R});
    for (auto cur:u) time+=2*(cur.second-cur.first+1);
    return (time<=t);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k>>t;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);
    for (int i=1;i<=k;i++) cin>>l[i]>>r[i]>>d[i];
    int l=0;
    int r=n+1;
    while (r-l>1){
        int mid=(l+r)/2;
        if (ok(a[mid])) l=mid;
        else r=mid;
    }
    cout<<l;
    return 0;
}