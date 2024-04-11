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
#define offset (110009)

int n,lis[5555],ans[5555],cnt[5555],ma,mind;

int main( ){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n;
    For(i,0,n) cin>>lis[i];
    For(l,0,n)
    {
        reset(cnt,0);
        ma=0;
        For(r,l,n)
        {
            cnt[lis[r]]++;
            if(cnt[lis[r]]>ma||cnt[lis[r]]==ma&&mind>lis[r])
            {
                ma=cnt[lis[r]];
                mind=lis[r];
            }
            ans[mind]++;
        }
    }
    For(i,1,1+n) cout<<ans[i]<<' ';
}