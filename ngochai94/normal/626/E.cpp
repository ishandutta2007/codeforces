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

long long n,lis[200005],s,cnt,l,r,ansl,ansr,ansp;
long double res;

int main( ){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios::sync_with_stdio(0);
    cin>>n;
    For(i,0,n) cin>>lis[i];
    sort(lis,lis+n);
    if(n<3)
    {
        cout<<n<<endl;
        For(i,0,n) cout<<lis[i]<<' ';
        return 0;
    }
    l=0;r=n-1;ansl=l;ansr=r;cnt=3;ansp=1;
    s=lis[0]+lis[1]+lis[r];
    res=1.0*s/cnt-lis[1];
    For(pivot,2,n-1)
    {
        s+=lis[pivot]-lis[l];
        l++;
        if(r-1>pivot&&(lis[r-1]+lis[l-1])*cnt>2*s)
        {
            //cout<<r<<' '<<pivot<<endl;
            r--;
            l--;
            cnt+=2;
            s+=lis[r]+lis[l];
        }
        if(1.0*s/cnt-lis[pivot]>res)
        {
            res=1.0*s/cnt-lis[pivot];
            ansp=pivot;
            ansl=l;
            ansr=r;
        }
    }
    if(res<0)
    {
        cout<<1<<endl<<lis[0];return 0;
    }
    cout<<n-ansr+ansp+1-ansl<<endl;
    For(i,ansl,ansp+1) cout<<lis[i]<<' ';
    For(i,ansr,n) cout<<lis[i]<<' ';
}