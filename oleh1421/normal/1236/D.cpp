#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const long long mod=1000000007ll;
vector<int>a[200001];
vector<int>b[200001];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,m,k;cin>>n>>m>>k;
    for (int i=1;i<=k;i++){
        int x,y;cin>>x>>y;
        a[x].push_back(y);
        b[y].push_back(x);
    }
    for (int i=1;i<=n;i++) a[i].push_back(m+1),a[i].push_back(0),sort(a[i].begin(),a[i].end());
    for (int i=1;i<=m;i++) b[i].push_back(n+1),b[i].push_back(0),sort(b[i].begin(),b[i].end());
    int x=1;
    int y=1;
    int v=1;
    int x1=1;
    int x2=n+1;
    int y1=0;
    int y2=m+1;
    ll res=1ll;
    int cnt=0;
    while (true){
        cnt++;
        if (v==1){
            int pos=lower_bound(a[x].begin(),a[x].end(),y)-a[x].begin();
            //cout<<*lower_bound(a[x].begin(),a[x].end(),y)<<endl;
            int nxt=min(y2-1,a[x][pos]-1);
            if (nxt==y && cnt>1) break;
            res+=(nxt-y)*1ll;
            y=nxt;
            y2=nxt;
        } else if (v==2){
            int pos=lower_bound(b[y].begin(),b[y].end(),x)-b[y].begin();
            int nxt=min(x2-1,b[y][pos]-1);
            if (nxt==x) break;
            res+=(nxt-x)*1ll;
            x=nxt;
            x2=nxt;
        } else if (v==3){
            int pos=lower_bound(a[x].begin(),a[x].end(),y)-a[x].begin()-1;
            int nxt=max(y1+1,a[x][pos]+1);
            if (nxt==y) break;
            res+=(y-nxt)*1ll;
            y=nxt;
            y1=nxt;
        } else if (v==4){
            int pos=lower_bound(b[y].begin(),b[y].end(),x)-b[y].begin()-1;
            int nxt=max(b[y][pos]+1,x1+1);
            //cout<<pos<<endl;
            if (nxt==x) break;
            res+=(x-nxt)*1ll;
            x=nxt;
            x1=nxt;
        }
        v++;
        if (v==5) v=1;
    }
    if (res+k*1ll==n*m*1ll) cout<<"Yes";
    else cout<<"No";
    return 0;
}