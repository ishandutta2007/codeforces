#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;
unordered_map<int,int>used;
int n,p,k;
int f(int x){
    int res=x;
    res*=res;
    res%=p;
    res*=res;
    res%=p;
    return ((res-k*x)%p+p)%p;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>p>>k;
    int res=0;
    for (int i=1;i<=n;i++){
        int x;cin>>x;
        res+=used[f(x)]++;
    }
    cout<<res;
    return 0;
}
//2 6 -2 -6  2