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

int n,k,lis[300005];

int main( ){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin>>n>>k;
    For(i,0,n) cin>>lis[i];
    int r=-1,ansl=0,ansr=-1;
    For(l,0,n)
    {
        if(l)
        {
            if(!lis[l-1]&&r>=l-1) k++;
        }
        r=max(r,l-1);
        while(r<n-1&&(lis[r+1]||k))
        {
            r++;
            if(!lis[r]) k--;
        }
        if(r-l>ansr-ansl)
        {
            ansr=r;
            ansl=l;
        }
        //cout<<l<<' '<<r<<endl;
    }
    cout<<ansr-ansl+1<<endl;
    For(i,ansl,ansr+1) lis[i]=1;
    For(i,0,n) cout<<lis[i]<<' ';
}