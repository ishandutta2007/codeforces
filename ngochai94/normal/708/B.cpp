#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a;i<b;i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define off 250555

long long a00,a11,a01,a10,tot,n0,n1;
map<long long, long long> m;

bool solve()
{
    if(n0+n1!=m[tot])
    {
        return false;
    }
    while(a01&&a01>=n1)
    {
        cout<<'0';
        n0--;
        a01-=n1;
    }
    //cout<<n1-a01<<endl;
    long long tmp=n1-a01;
    For(i,0,tmp)
    {
        n1--;
        cout<<'1';
    }
    if(n0)
    {
        n0--;
        cout<<'0';
    }
    For(i,0,n1) cout<<'1';
    For(i,0,n0) cout<<'0';
    return true;
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin>>a00>>a01>>a10>>a11;
    tot=a00+a11+a01+a10;
    if(tot==0)
    {
        cout<<'1';return 0;
    }
    for(long long i=0;i<1000003;i++) m[i*(i-1)/2] = i;
    if(!m.count(a00)||!m.count(a11)||!m.count(tot))
    {
        cout<<"Impossible";
        return 0;
    }
    n0=m[a00];
    n1=m[a11];
    //cout<<n0;
    if(solve()) return 0;
    if(n0==1)
    {
        n0=0;
        if(solve()) return 0;
    }
    if(n1==1)
    {
        n1=0;
        if(solve()) return 0;
    }
    cout<<"Impossible";
}