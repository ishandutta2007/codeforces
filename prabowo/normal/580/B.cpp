#include<iostream>
#include<algorithm>
#include<utility>
using namespace std;
#define LL long long

LL n,d,ans=-1,p[100005];
pair<LL,LL> a[100005];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> d;
    for(int i=1; i<=n; i++)cin >> a[i].first >> a[i].second;
    sort(a+1,a+n+1);
    a[n+1]=make_pair(1000000009,1000000009);
    for(int i=1; i<=n; i++)p[i]=p[i-1]+a[i].second;
    for(int i=1; i<=n; i++){
        int l=upper_bound(a+i,a+n+1,make_pair(a[i].first+d,(LL)0))-a;
        ans=max(ans,p[l-1]-p[i-1]);
    //  cout << l << " " << ans << endl;
    }
    cout << ans << endl;
    return 0;
}