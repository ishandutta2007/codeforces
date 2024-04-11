#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
//#define int long long
#define endl '\n'
typedef long long ll;
using namespace std;
bool ban[1000001];
int d1[1000001];
int d[1000001];
int f[1000001];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;cin>>n>>m;
    vector<pair<int,int> >v;
    for (int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        v.push_back({a,b});
        d[a]++;
        d[b]++;
        d1[a]++;
        d1[b]++;
    }
    for (int i=1;i<=n;i++) f[i]=(d[i]+1)/2;
    int cnt=0;
    int k=(m+n+1)/2;
    while (m-cnt>k){
        cnt=0;
        random_shuffle(v.begin(),v.end());
        for (int i=1;i<=n;i++) d[i]=d1[i];
        for (int i=1;i<=m;i++) ban[i]=false;
        for (int i=0;i<m;i++){
            if (d[v[i].first]>f[v[i].first] && d[v[i].second]>f[v[i].second]){
                d[v[i].first]--;
                d[v[i].second]--;
                ban[i+1]=true;
                cnt++;
            }
        }
    }
    cout<<m-cnt<<endl;
    for (int i=1;i<=m;i++) if (!ban[i]) cout<<v[i-1].first<<" "<<v[i-1].second<<endl;
    return 0;
}