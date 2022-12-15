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

long long n,x[100005],y[100005],x1,x2,y1,y2,ans;
pair<long double,int> p[100005];

long double dis(long long x0,long long y0,long long x1,long long y1,long long x2,long long y2)
{
    long double deno=(y2-y1)*x0;
    deno-=(x2-x1)*y0;
    deno+=x2*y1;
    deno-=x1*y2;
    long double nume=(y2-y1)*(y2-y1);
    nume+=(x2-x1)*(x2-x1);
    //cout<<deno<<' '<<nume<<endl;
    if(abs(deno)<eps) return 10000000000.0;
    return abs(deno)/sqrt(nume);
}

int main( ){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    //cout<<dis(0,1,0,0,1,1)<<endl;return 0;
    cin>>n;
    For(i,0,n)
    {
        cin>>x[i]>>y[i];
        //p[i]={dis(x,y,x1,y1,x2,y2),i};
    }
    For(i,3,n+1) p[i]={dis(x[i-1],y[i-1],x[0],y[0],x[1],y[1]),i};
    sort(p+3,p+n+1);
    ans=p[3].second;

    For(i,3,n+1) p[i]={dis(x[i-1],y[i-1],x[0],y[0],x[ans-1],y[ans-1]),i};
    p[2]={dis(x[1],y[1],x[0],y[0],x[ans-1],y[ans-1]),2};
    sort(p+2,p+n+1);
    //For(i,2,n+1) cout<<p[i].first<<' '<<p[i].second<<endl;
    cout<<1<<' '<<ans<<' '<<p[2].second;
}