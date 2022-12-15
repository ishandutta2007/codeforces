#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a;i<b;i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define off 250555

int n,h,m;
char c;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin >> n;
    cin >> h >> c >> m;
    if(n==12)
    {
        if(h<1||h>12)
        {
            h%=10;
            if(!h) h=10;
        }
    }
    else
    {
        if(h>23) h%=10;
    }
    if(m>59) m%=10;
    printf("%02d:%02d",h,m);
}