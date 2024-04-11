#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define f first
#define s second
#define all(x) x.begin(),x.end()
using namespace std;

const int mod=1e9+7;
int add(int a,int b)
{
a+=b;
if(a>=mod)
a-=mod;
return a;
}
int mul(int a,int b)
{
return (ll)a*b%mod;
}
int main()
{
int t;
scanf("%i",&t);while(t--){
    int a,b,c;
    cin >> a >> b >> c;
    int koliko=min(b,c/2);
    int stones=koliko;
    b-=koliko;
    printf("%i\n",(koliko+min(a,b/2))*3);
    }
    return 0;
}