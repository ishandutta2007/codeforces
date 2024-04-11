//#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
//#define int long long
#define endl '\n'
typedef long long ll;

using namespace std;
bool a[155][155];
char b[155][155];
char f(int x){
    if (x<=26) return (x-1+'a');
    if (x<=52) return (x-27+'A');
    return (x-53+'0');
}
void solve(){
    int n,m,k;cin>>n>>m>>k;
    int sum=0;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            char c;cin>>c;
            a[i][j]=(c=='R');
            sum+=a[i][j];
        }
    }
    int x=(sum/k);
    int c=sum%k;
    vector<int>v;
    for (int i=0;i<c;i++) v.push_back(x+1);
    while (v.size()<k) v.push_back(x);
    vector<int>u;
    int sm=0;
    for (int i=0;i<k;i++){
        sm+=v[i];
        u.push_back(sm);
    }


    int cnt=0;
    for (int i=1;i<=n;i++){
        if (i%2==0){
            for (int j=m;j>=1;j--){
                cnt+=a[i][j];
                int it=lower_bound(u.begin(),u.end(),cnt)-u.begin()+1;
                b[i][j]=f(it);
            }
        } else {
            for (int j=1;j<=m;j++){
                cnt+=a[i][j];
                int it=lower_bound(u.begin(),u.end(),cnt)-u.begin()+1;
                b[i][j]=f(it);
            }
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cout<<b[i][j];
        }
        cout<<endl;
    }


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