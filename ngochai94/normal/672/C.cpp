#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define mod 1000000007
#define reset(s,val) memset(s,val,sizeof(s))
#define eps 1e-9
#define pi acos(-1)
#define sqr(x) (x)*(x)
#define two(x) (1<<(x))

long long ax,ay,bx,by,tx,ty,x[100005],y[100005],n;
long double dis[100005], force,ans;
pair<long double, int> offa[100005], offb[100005];

long double f(long long x,long long y,long long xx,long long yy) {
    return sqrt(sqr(x-xx)+sqr(y-yy));
}

int main( ){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>ax>>ay>>bx>>by>>tx>>ty;
    cin>>n;
    force = 0;
    For(i,0,n) {
        cin>>x[i]>>y[i];
        dis[i] = f(tx,ty,x[i],y[i]);
        force += dis[i]*2;
        offa[i] = {f(ax,ay,x[i],y[i])-dis[i], i};
        offb[i] = {f(bx,by,x[i],y[i])-dis[i], i};
    }
    cout<<setprecision(11);
    if(n==1) {
        cout<<min(offa[0].first,offb[0].first) + force;
        return 0;
    }
    sort(offa,offa+n);
    sort(offb,offb+n);
    ans = min(offa[0].first, offb[0].first);
    if(offa[0].second!=offb[0].second) ans = min(ans,ans+max(offa[0].first,offb[0].first));
    else {
        ans = min(ans,offa[0].first+offb[1].first);
        // cout<<force+ans<<' '<<force+offa[0].first+offb[1].first<<endl;
        // cout<<force+ans<<' '<<force+offa[1].first+offb[0].first<<endl;
        ans = min(ans,offa[1].first+offb[0].first);
    }
    // cout<<offa[0].first<<endl<<offb[0].first<<endl;
    // cout<<force<<endl;
    cout<<ans+force<<endl;
}