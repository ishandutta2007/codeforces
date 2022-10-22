#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define vb vector<bool>
#define ii pair<int,int>
#define vvi vector<vi>
#define vvb vector<vb>
#define vii vector<ii>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define loop(i,s,e) for(int i=s;i<e;i++)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 1e18, MOD=1e9+7;


int32_t main(){
    ios_base::sync_with_stdio(false);
    int a; cin>>a;
    vb num(6); loop(i,0,6) num[i]=(a&(1<<i));
    vb next(6); 
    next[4] = num[0]; next[1] = num[1]; next[3] = num[2];
    next[2] = num[3]; next[0] = num[4]; next[5] = num[5];
    int ans = 0;
    loop(i,0,6) ans+=next[i]*(1<<i);
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ a.cpp -o a & a
2
*/