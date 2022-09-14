#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define int long long
#define MINX(a,b) if(a>b) a=b;
#define MAXX(a,b) if(a<b) a=b;
typedef long long ll;
using namespace std;
int a[300011];
int b[300011];
int pref[300011];
int suf1[300011];
int suf2[300011];
int sum[300011];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) cin>>b[i];
    pref[1]=b[1];
    for (int i=2;i<=n;i++){
        pref[i]=pref[i-1];
        if (i%2==0){
            pref[i]+=2*(i-1)*b[i]+(2*i-1)*a[i];
        } else {
            pref[i]+=2*(i-1)*a[i]+(2*i-1)*b[i];
        }
    }
    suf1[n]=b[n];
    suf2[n]=a[n];
    sum[n]=a[n]+b[n];
    for (int i=n-1;i>=1;i--){
        suf1[i]=suf1[i+1]+sum[i+1]+b[i]*(2*(n-i)+1);
        suf2[i]=suf2[i+1]+sum[i+1]+a[i]*(2*(n-i)+1);
        sum[i]=sum[i+1];
        sum[i]+=a[i]+b[i];
    }
    int res=0;
    for (int i=0;i<=n;i++){
        int cur=pref[i];
        if (i%2){
            cur+=suf2[i+1]+sum[i+1]*(i+i);
        } else {
            cur+=suf1[i+1]+sum[i+1]*(i+i);
        }
        MAXX(res,cur);
    }
    cout<<res;
    return 0;
}
//2 6 -2 -6  2