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
const int INF = 4e18, MOD = 1e9+7;

int m = 52;
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,t; cin>>n>>t;
    string ss; cin>>ss;
    vi s(n);
    loop(i,0,n) s[i] = ss[i]-'a';
    t-=int(1)<<s[n-1];
    t+=int(1)<<s[n-2];
    n = n-2;
    vi cnt(m);
    loop(i,0,n) cnt[s[i]]++;
    loopr(i,0,m){
        //cout<<"I: "<<tar[i]<<" "<<cnt[i]<<endl;
        loop(x,0,cnt[i]){
            if (t>0) t-=(int(1)<<i);
            else t+=(int(1)<<i);
        }
    }
    if (t==0) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
/*
color a
cls
g++ c.cpp -o a & a
7 -475391
qohshra


2 -1
ba

3 -7
abc

3 1
abc


*/