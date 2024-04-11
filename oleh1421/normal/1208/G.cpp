//#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
//#define int long long
#define endl '\n'
typedef long long ll;
using namespace std;
int fi[2000001];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;cin>>n>>k;
    for (int i=1;i<=n;i++) fi[i]=i;
    for (int i=2;i<=n;i++){
        if (fi[i]==i){
            for (int j=i;j<=n;j+=i){
                fi[j]/=i;
                fi[j]*=i-1;
            }
        }
    }
    vector<int>v;
    for (int i=3;i<=n;i++) v.push_back(fi[i]);
    sort(v.begin(),v.end());
    ll sum=0;
    for (int i=0;i<k;i++) sum+=v[i]*1ll;
    cout<<sum+1ll+(k>1)<<endl;
    return 0;
}