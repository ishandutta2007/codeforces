//#define DEBUG
//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
typedef long double ld;
const ll inf=1000000000000000001ll;
const ll mod=1000000007;
using namespace std;
mt19937 rnd(time(NULL));
const int N=400010;
int a[N],b[N];
void solve(){
    int k,n,m;cin>>k>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=m;i++) cin>>b[i];
    vector<int>ans;
    int i=1,j=1;
    a[n+1]=1000000001;
    b[m+1]=1000000001;
    while (i<=n+1 && j<=m+1 && i+j<=n+m+1){
        if (a[i]==0){
            k++;
            i++;
            ans.push_back(0);
        } else if (b[j]==0){
            k++;
            j++;
            ans.push_back(0);
        } else if (a[i]<b[j]){
            if (a[i]>k){
                cout<<-1<<endl;
                return;
            }
            ans.push_back(a[i]);
            i++;
        } else {
            if (b[j]>k){
                cout<<-1<<endl;
                return;
            }
            ans.push_back(b[j]);
            j++;
        }
    }
    for (int i:ans) cout<<i<<" ";
    cout<<endl;


}
int main()
{
//    freopen("events.in","r",stdin);
//    freopen("events.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/**
1
4 4
1 2
2 3
1 4
4 3
**/