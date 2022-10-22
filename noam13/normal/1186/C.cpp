#include<bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define loop(i,s,e) for(int i=s;i<e;i++)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF=4e18;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string a,b; cin>>a>>b;
    int m=b.size(),n=a.size();
    int cnta=0,cntb=0;
    loop(i,0,m){
        if (a[i]=='1') cnta++;
        if (b[i]=='1') cntb++;
    }
    int ans=((cnta-cntb)%2==0);
    loop(i,m,n){
        if (a[i]=='1') cnta++;
        if (a[i-m]=='1') cnta--;
        ans+=((cnta-cntb)%2==0);
    }
    cout<<ans<<endl;
    return 0;
}