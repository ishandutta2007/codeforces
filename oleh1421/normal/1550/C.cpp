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
int a[N];

void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    int res=0;
    for (int l=1;l<=n;l++){
        for (int r=l;r<=n;r++){
            bool ok=true;
            for (int i=l;i<=r;i++){
                for (int j=i+1;j<r;j++){
                    if (a[i]<=a[j] && a[j]<=a[r]) ok=false;
                    if (a[i]>=a[j] && a[j]>=a[r]) ok=false;
                }
            }
            if (!ok) break;
            res++;
        }
    }
    cout<<res<<endl;

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
5
6 9 1 9 6
**/