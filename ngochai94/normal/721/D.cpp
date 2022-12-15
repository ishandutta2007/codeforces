#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a;i<b;i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define off 250555

long long n, k, x, lis[200005], ind, neg, zero;
set<pair<long long, long long> > s;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>k>>x;
    For(i,0,n)
    {
        cin>>lis[i];
        if(abs(lis[i])<abs(lis[ind])) ind = i;
        neg+=(lis[i]<0)?1:0;
    }
    //cout<<neg<<endl;
    if(neg%2==0)
    {
        int req = 1 + abs(lis[ind])/x;
        //cout<<req<<endl;
        if(req>=k)
        {
            if(lis[ind]>=0) lis[ind]-=x*k;
            else lis[ind]+=x*k;
            For(i,0,n) cout<<lis[i]<<' ';
            return 0;
        }
        if(lis[ind]>=0) lis[ind]-=req*x;
        else lis[ind]+=req*x;
        k-=req;
    }
    //For(i,0,n) cout<<lis[i]<<' ';
    //cout<<k<<endl;
    For(i,0,n) s.insert({abs(lis[i]),i});
    while(k--)
    {
        auto it = s.begin();
        long long indd = it->second;
        //cout<<indd<<endl;
        if(lis[indd]<0) lis[indd]-=x;
        else lis[indd]+=x;
        //cout<<indd<<' '<<lis[indd]<<endl;
        s.erase(it);
        s.insert({abs(lis[indd]),indd});
    }
    For(i,0,n) cout<<lis[i]<<' ';
}