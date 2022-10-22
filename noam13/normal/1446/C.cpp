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

const int LOG = 34;

int solve(vi &a){
    int n = a.size();
    if (n==0) return 0;
    if (n==1) return 1;
    vvi nums(LOG);
    loop(i,0,n){
        int x = a[i];
        int j = 0;
        while(x) x/=2, j++;
        nums[j].pb(a[i]^(1<<(j-1)));
    }
    vi suf(LOG+1,0);
    loopr(i,0,LOG) suf[i] = suf[i+1] + (nums[i].size()!=0);
    if (suf[1]==0){
        return nums[0].size();
    }
    vi sol(LOG);
    loop(i,0,LOG) sol[i] = solve(nums[i]);
    int ans = 0, c = 0;
    loop(i,0,LOG){
        if (sol[i]==0) continue;
        chkmax(ans, sol[i] + suf[i+1] + (c!=0));
        c=1;
    }
    return ans;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    vi a(n);
    loop(i,0,n){
        cin>>a[i];
    }
    cout<<n-solve(a)<<endl;
    return 0;
}
/*
color a
cls
g++ c.cpp -o a & a
4
4 5 6 7

5
0 1 5 2 6

*/