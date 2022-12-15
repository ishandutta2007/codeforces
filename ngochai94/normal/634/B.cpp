#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(long long i=a;i<b;i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define mod 1000000007
#define pi acos(-1)
#define eps 0.000001
#define pb push_back

long long s,x;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>s>>x;
    int cnt=0;
    if(s<x||(s-x)&1||((s-x)/2)&x)
    {
        cout<<0;return 0;
    }
    For(i,0,60) if(x&(1ll<<i)) cnt++;
    //cout<<cnt<<endl;
    if(s==x) cout<<(1ll<<(cnt))-2;
    else cout<<(1ll<<cnt);
}