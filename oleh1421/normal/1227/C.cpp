//#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
//#define int long long
#define endl '\n'
typedef long long ll;
using namespace std;
int a[300001];
void solve(){
    int n,k;cin>>n>>k;
    for (int i=1;i<=n;i++){
        char c;cin>>c;
        a[i]=(c=='(')-(c==')');
    }
    vector<pair<int,int> >ans;
    for (int i=1;i<k;i++){
        if (a[i+i-1]==1 && a[i+i]==-1) continue;
        if (a[i+i-1]==-1 && a[i+i]==1){
            ans.push_back({i+i-1,i+i});
            continue;
        }
        if (a[i+i-1]==1){
            for (int j=i+i;j<=n;j++){
                if (a[j]==-1){
                    ans.push_back({i+i,j});
                    for (int t=j;t>i+i;t--){
                        a[t]=a[t-1];
                    }
                    a[i+i]=-1;
                    break;
                }
            }
        } else {
            for (int j=i+i;j<=n;j++){
                if (a[j]==1){
                    ans.push_back({i+i,j});
                    for (int t=j;t>i+i;t--){
                        a[t]=a[t-1];
                    }
                    a[i+i]=1;
                    break;
                }
            }
            ans.push_back({i+i-1,i+i});
            swap(a[i+i-1],a[i+i]);
        }
    }
    for (int i=k+k-1;i<=n/2+k-1;i++){
        if (a[i]==1) continue;
        for (int j=i+1;j<=n;j++){
            if (a[j]==1){
                ans.push_back({i,j});
                for (int t=j;t>i;t--){
                    a[t]=a[t-1];
                }
                a[i]=1;
                break;
            }
        }
    }
    cout<<ans.size()<<endl;
    for (auto cur:ans) cout<<cur.first<<" "<<cur.second<<endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}