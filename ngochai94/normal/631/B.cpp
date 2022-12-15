#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(long long i=a;i<b;i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define mod 1000000007
#define pi acos(-1)
#define eps 0.000001
#define pb push_back

long long n,m,k,r[5555],c[5555],tr[5555],tc[5555],t,x,y;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>m>>k;
    For(tt,1,k+1)
    {
        cin>>t>>x>>y;
        x--;
        if(t==1)
        {
            r[x]=y;
            tr[x]=tt;
        }
        else
        {
            c[x]=y;
            tc[x]=tt;
        }
    }
    For(i,0,n)
    {
        For(j,0,m)
        {
            if(tr[i]>tc[j]) cout<<r[i]<<' ';
            else cout<<c[j]<<' ';
        }
        cout<<endl;
    }
}