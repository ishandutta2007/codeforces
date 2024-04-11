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

int n,lis[1111];

int main( ){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n;
    int l=0,r=n-1;
    For(i,0,n) cin>>lis[i];
    sort(lis,lis+n);
    For(i,0,n)
    {
        if(i&1)
        {
            cout<<lis[r--];
        }
        else
        {
            cout<<lis[l++];
        }
        cout<<' ';
    }
}