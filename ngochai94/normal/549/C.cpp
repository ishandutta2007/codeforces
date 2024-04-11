#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define mod 1000000007
#define reset(s,val) memset(s,val,sizeof(s))
#define eps 1e-12
#define pi acos(-1)
#define sqr(x) (x)*(x)
#define two(x) (1<<(x))

int n,k,a,o,e;

int main( ){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios::sync_with_stdio(0);
    cin>>n>>k;
    For(i,0,n)
    {
        cin>>a;
        if(a&1) o++;
        else e++;
    }
    if(k==n)
    {
        if(o&1) cout<<"Stannis";
        else cout<<"Daenerys";
        return 0;
    }
    if((n-k)&1)
    {
        int beat=(n-k)>>1;
        if(beat>=e&&k%2==0) cout<<"Daenerys";
        else if(beat>=o) cout<<"Daenerys";
        else cout<<"Stannis";
    }
    else
    {
        int beat=(n-k)>>1;
        if(beat>=e&&k&1) cout<<"Stannis";
        else cout<<"Daenerys";
    }
}