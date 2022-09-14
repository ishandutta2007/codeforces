//#define DEBUG
//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
typedef long double ld;
const ll inf=2000000000000000001ll;
const int mod=31607;
using namespace std;
mt19937 rnd(time(NULL));
const int N=200010;
int c[N];
vector<int>g[N];
int cnt[N];
bool used[N];
int last[N];
int a[N],b[N];
void solve(){
    int n,k;cin>>n>>k;
    for (int i=0;i<=n;i++) used[i]=false,last[i]=0;
    for (int i=1;i<=n*k;i++) cin>>c[i],g[c[i]].push_back(i),cnt[i]=(n+k-2)/(k-1);
    int pos=1;
    for (int it=1;it<=n;it++){
        while (cnt[pos]<=0) pos++;
        for (int j=1;j<=n;j++) last[j]=0;
        for (int j=pos;j<=n*k;j++){
            if (used[c[j]]) continue;
            if (last[c[j]]){
                a[c[j]]=last[c[j]];
                b[c[j]]=j;
                for (int t=1;t<=j;t++) cnt[t]--;
                used[c[j]]=true;
                break;
            }
            last[c[j]]=j;
        }
    }
    for (int i=1;i<=n;i++) cout<<a[i]<<" "<<b[i]<<endl;

}
int main()
{
//    freopen("events.in","r",stdin);
//    freopen("events.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}
//5 10 5 9
/**
10 6
14 6
2 20
9 10
13 18
15 12
11 7
**/