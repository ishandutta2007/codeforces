#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
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
const int INF=4e18;

int n,d;
vi a;

bool can(int k){
    int sum=0;
    loop(i,0,d) sum+=a[i];
    loop(i,d,n){
        if (sum<k) return false;
        sum+=a[i]-a[i-d];
    }
    return true;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>d; n--;
    a.resize(n,0);
    int ans=INF,sum=0;
    loop(i,0,n) cin>>a[i];
    loop(i,0,d) sum+=a[i];
    loop(i,d,n){
        chkmin(ans,sum);
        sum+=a[i]-a[i-d];
    }
    cout<<min(ans,sum)<<endl;
    /*int l=0,r=INF,mid;
    for(;l<r-1;){
        mid=(l+r)/2;
        if (can(mid)) l=mid;
        else r=mid;
    }
    cout<<l<<endl;*/
    return 0;
}
/*
10 5
0 0 1 0 2 0 0 1 0
*/