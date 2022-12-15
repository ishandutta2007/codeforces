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

int n,m,k,val,lis[111],ans;

int main( ){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>m>>k;
    n*=m;
    For(i,0,k) cin>>lis[i];
    while(n--)
    {
        cin>>val;
        For(i,0,k) if(lis[i]==val)
        {
            ans+=i+1;
            for(int j=i;j>0;j--) swap(lis[j],lis[j-1]);
            break;
        }
    }
    cout<<ans;
}