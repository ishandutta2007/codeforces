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


int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,k; cin>>n>>k;
    k-=n;
    int ans = 0;
    vi a(n); loop(i,0,n) cin>>a[i];
    priority_queue<ii> q;
    auto getc = [&](int x, int k){
        int amt = x%k;
        x/=k;
        int v = (k-amt) * x * x;
        x++;
        return v + amt * x*x;
    };
    auto getdc = [&](int x, int k){
        if (x==k) return int(0);
        return -(getc(x,k+1) - getc(x,k));
    };
    //cout<<getc(10,1)<<" "<<getc(10,2)<<" "<<getc(10,3)<<endl;
    //cout<<getdc(10,1)<<endl;
    vi cnt(n,1);
    loop(i,0,n){
        ans+=a[i]*a[i];
        q.push({getdc(a[i], cnt[i]), i});
    }
    loop(kk,0,k){
        int dv = q.top().x, i = q.top().y; q.pop();
        cnt[i]++;
        //cout<<"DV: "<<dv<<endl;
        ans-=dv;
        q.push({getdc(a[i], cnt[i]), i});
    }
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ e.cpp -o a & a
3 6
5 3 1


*/