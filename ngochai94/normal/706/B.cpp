#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define mod 1000000007
#define reset(s,val) memset(s,val,sizeof(s))
#define eps 1e-8
#define pi acos(-1)
#define sqr(x) (x)*(x)
#define two(x) (1<<(x))

int n,lis[100005],q,v;

int main( ){
    // freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin>>n;
    For(i,0,n) {
        cin>>v;
        lis[v]++;
    }
    For(i,1,100005) lis[i]+=lis[i-1];
    cin>>q;
    while(q--) {
        cin>>v;
        if(v>100003) cout<<lis[100003]<<endl;
        else cout<<lis[v]<<endl;
    }
}