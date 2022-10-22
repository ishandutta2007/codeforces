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
    int n,x;cin>>n>>x;
    vi a(n);
    loop(i,0,n) cin>>a[i];
    int maxi=0,sum=0,sum1=0,sum2=0;
    loop(i,0,n){
        sum2=max(sum2+a[i],sum1+a[i]);
        sum1=max(sum1+a[i]*x,sum+a[i]*x);
        sum+=a[i];
        chkmax(maxi,sum);
        chkmax(maxi,sum1);
        chkmax(maxi,sum2);
        if (sum<0) sum=0;
        if (sum1<0) sum1=0;
        if (sum2<0) sum2=0;
    }
    cout<<maxi<<endl;
    return 0;
}