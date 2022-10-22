#include<bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define x first
#define y second
#define pb push_back
#define loop(i,s,e) for(int i=s;i<e;i++)
#define abs(a) ((a)>0?a:-(a))
#define chkmax(a,b) a=max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF=4e18;


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin>>n;
    int ans=1;
    loop(i,1,n) ans+=i*4;
    cout<<ans<<endl;
    return 0;
}