#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(long long i=a;i<b;i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define mod 1000000007
#define pi acos(-1)
#define eps 0.000001
#define pb push_back

long long a,b,c;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>a>>b>>c;
    if(!c)
    {
        if(a==b) cout<<"YES";
        else cout<<"NO";
    }
    else if ( c>0)
    {
        if(b>=a&&(b-a)%c==0) cout<<"YES";
        else cout<<"NO";
    }
    else
    {
        if(b<=a&&(a-b)%c==0) cout<<"YES";
        else cout<<"NO";
    }
}