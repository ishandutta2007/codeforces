#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(long long i=a;i<b;i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define mod 1000000007
#define pi acos(-1)
#define eps 0.000001
#define pb push_back

int n,lis[200005],pos[200005],cnt,val;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n;
    cnt=0;
    For(i,0,n)
    {
        cin>>val;
        if(val)
        {
            lis[cnt]=val;
            cnt++;
        }
    }
    cnt=0;
    For(i,0,n)
    {
        cin>>val;
        if(val)
        {
            pos[val]=cnt;
            cnt++;
        }
    }
    //cout<<pos[1]<<endl;
    For(i,0,n-2)
    {
        if((pos[lis[i]]+1)%(n-1)!=pos[lis[i+1]])
        {
            //cout<<(pos[lis[i]]+1)%(n-1)<<endl;
            cout<<"NO";return 0;
        }
    }
    cout<<"YES";
}