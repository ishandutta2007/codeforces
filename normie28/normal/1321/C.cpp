#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)

#define FILE_IN "tree.inp"
#define FILE_OUT "tree.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define pow2(x) (ll(1)<<x)
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
typedef long long ll;
ll n,m,i,j,k,t,t1,a[200001],diff[200001], sum[200001],nxt[200001],used[200001],aad,bad;
vector<ll> v,v2;
int main(){
    cin>>n;
    for (i=0;i<n;i++)
    {
        char c;
        cin>>c;
        v.push_back(c-97);
    }
    for (i=24;i>=0;i--)
    {
        k=0;
        aad=0;bad=0;
 //       cout<<i<<endl;
        for (j=0;j<v.size();j++)
        {
//            cout<<v[j]<<' ';
            if (v[j]==i) bad++;
            else if (v[j]==i+1) aad++;
            else
            {
                if (bad) 
                {
                    t+=aad;
                    for (t1=k;t1<j;t1++)
                    a[t1]=1;
                }
                k=j+1;
                aad=0;
                bad=0;
            }
            
        }
                if (bad) 
                {
                    t+=aad;
                    for (t1=k;t1<j;t1++)
                    a[t1]=1;
                }
                k=j+1;
                aad=0;
                bad=0;
//                cout<<endl;
                for (j=0;j<v.size();j++)
                {
//                    cout<<a[j]<<' ';
                if (!((a[j])and(v[j]==i+1))) v2.push_back(v[j]);
                }
                v=v2;
                v2.clear();
                for (j=0;j<v.size();j++) a[j]=0;
 //       cout<<endl;
    }
    cout<<t;
}