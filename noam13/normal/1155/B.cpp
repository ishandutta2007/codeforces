#include<bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define loop(i,s,e) for(int i=(s);i<(e);i++)
#define chkmin(a,b) a=min((int)(a),(int)(b))
#define chkmax(a,b) a=max(a,b)
using namespace std;
const int INF=4*1e18;


int32_t main(){
    int n;cin>>n;
    string s;cin>>s;
    int cnt=0;
    int turn=(n-11)/2;
    vi pos(0);
    loop(i,0,n) if (s[i]=='8') pos.pb(i);
    if (pos.size()<=turn || pos[turn]>n-11) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    return 0;
}