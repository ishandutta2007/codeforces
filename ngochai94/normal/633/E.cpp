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

long long n,k,v[1000006],c[1000006],curv,curc,ans[1000006],vm[1000006],cm[1000006];
stack<long long> smax,smin;
long double e,cur;

int main( ){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>k;
    For(i,0,n)
    {
        cin>>v[i];
        v[i]*=100;
    }
    For(i,0,n)
    {
        cin>>c[i];
    }
    vm[n-1]=v[n-1];cm[n-1]=c[n-1];
    smax.push(vm[n-1]);smin.push(cm[n-1]);
    ans[n-1]=min(vm[n-1],cm[n-1]);
    for(int i=n-2;i>=0;i--)
    {
        vm[i]=v[i];cm[i]=c[i];
        while(!smax.empty()&&(smin.top()>=cm[i]||smin.top()>vm[i]))
        {
            vm[i]=max(vm[i],smax.top());
            cm[i]=min(cm[i],smin.top());
            smax.pop();
            smin.pop();
        }
        smax.push(vm[i]);
        smin.push(cm[i]);
        ans[i]=min(vm[i],cm[i]);
    }
    //For(i,0,n) cout<<ans[i]<<' ';cout<<endl;
    sort(ans,ans+n);
    cur=1.0*k/n;
    e=cur*ans[0];
    For(i,1,n-k+1)
    {
        cur*=1-1.0*(k-1)/(n-i);
        e+=cur*ans[i];
    }
    cout<<setprecision(11)<<e;
}