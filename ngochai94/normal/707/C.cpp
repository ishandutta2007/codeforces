#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a;i<b;i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define off 250555

long long n,b;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin>>n;
    b=1;
    while(n%2==0&&n!=4)
    {
        n/=2;b*=2;
    }
    if(n==1) cout<<-1;
    else
    {
        if(n&1)
        {
            long long x=(n*n)/2;
            cout<<x*b<<' '<<(x+1)*b;
        }
        else
        {
            cout<<3*b<<' '<<5*b;
        }
    }
}