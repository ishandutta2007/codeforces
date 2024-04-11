#include <bits/stdc++.h>
//#define int long long
typedef long long ll;
using namespace std;
int x1[5001];
int y1[5001];
int x2[5001];
int y2[5001];
bitset<5010>a[5010];
bitset<5010>b[5010];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>x1[i]>>y1[i]>>x2[i]>>y2[i];
        if (x1[i]>x2[i] || y1[i]>y2[i]){
            swap(x1[i],x2[i]);
            swap(y1[i],y2[i]);
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=i+1;j<=n;j++){
            if ((x1[i]==x2[i] && y1[j]==y2[j] && x1[j]<=x1[i] && x2[j]>=x1[i] && y1[i]<=y1[j] && y2[i]>=y1[j]) ||(x1[j]==x2[j] && y1[i]==y2[i] && x1[i]<=x1[j] && x2[i]>=x1[j] && y1[j]<=y1[i] && y2[j]>=y1[i])){
                a[i][j]=1;
                a[j][i]=1;
                b[i][j]=1;
                b[j][i]=1;
            }
        }
    }
    ll res=0ll;
    vector<int>v;
    vector<int>u;
    for (int i=1;i<=n;i++){
        if (x1[i]==x2[i]) v.push_back(i);
        else u.push_back(i);
    }
    if (v.size()>u.size()) swap(v,u);
    for (int i=0;i<v.size();i++){
        for (int j=i+1;j<v.size();j++){
            int x=v[i];
            int y=v[j];
            int cnt=(a[x]&b[y]).count();
            res+=cnt*(cnt-1ll)/2ll*1ll;
        }
    }
    cout<<res;
    return 0;
}
//2 6 -2 -6  2