#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define loop(i,s,e) for(int i=s;i<e;i++)
#define loopr(i,s,e) for(int i=e-1;i>=s;i--)
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 4e18;

int solve(){
    int n; cin>>n;
    string a,b; cin>>a>>b;
    int m = 20;
    vvb need(m, vb(m,0));
    loop(i,0,n){
        a[i]-='a'; b[i]-='a';
        if (b[i]<a[i]) return cout<<-1<<endl,0;
        need[a[i]][b[i]]=1;
    }
    int ans=0;
    loop(i,0,m){
        int j=i+1;
        while(j<m && !need[i][j])  j++;
        if (j==m) continue;
        ans++;
        loop(k,j+1,m) if(need[i][k]) need[j][k]=1;
    }
    cout<<ans<<endl;
    return 0;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int t; cin>>t;
    loop(i,0,t) solve();
    return 0;
}
/*
color a
cls
g++ a.cpp -o a & a
5
3
aab
bcc
4
cabc
abcb
3
abc
tsr
4
aabd
cccd
5
abcbd
bcdda

*/