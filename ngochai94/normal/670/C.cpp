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

int n,m,ans,m1,m2,a[200005],b[200005],x,y;
map<int,int> dic;

int main( ){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n;
    ans=1;
    For(i,0,n)
    {
        int val;
        cin>>val;
        dic[val]++;
    }
    cin>>m;
    For(i,0,m) cin>>a[i];
    For(i,0,m) cin>>b[i];
    For(i,0,m)
    {
        int aa=a[i],bb=b[i];
        x=dic[aa];
        y=dic[bb];
        if(x>m1||x==m1&&y>m2)
        {
            ans=i+1;
            m1=x;
            m2=y;
        }
    }
    cout<<ans;
}