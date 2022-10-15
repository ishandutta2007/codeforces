// Thanks to robs77 for this template
/***********HEADER***************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
/***********MACROS***************/
//#define int long long
#define inf 100000000000000000 
#define ll  long long 
 
/*********VARIABLE****************/
using namespace std;
typedef pair<ll,ll> ii;
/******************************/
 const int   N   = 200000 + 1;
const int   mod = 1000000000 + 7;
int c[N];
/*********FUNCTIONS**************/

 
int add(int a,int b)    {
    a += b;
    if(a >= mod)a -= mod;
    return  a;
}
int mul(int a,int b)    {
    return  1ll * a * b % mod;
}
int Pow(int a,int b)    {
    int ans = 1;
    while (b)   {
        if(b & 1)   ans = mul(ans,a);
        a = mul(a,a);   b >>= 1;
    }
    return  ans;
}
 
 
/***********MAIN**************/
 
int main()  {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int n;  cin >> n;
 
    for(int i = 1 ; i <= n ; ++i)   {
        int x;  cin >> x;
        c[x]++;
    }
 
    int ch = 0;
 
    for(int i = 2 ; i <  N ; ++i)   ch |= (c[i] & 1);
 
    int exp = 1;
    int cur = 2 * mod - 2;
 
    if (ch) {
        for(int i = 2 ; i <  N ; ++i)
            exp = 1ll * exp * (c[i] + 1) % cur;
        exp /= 2;
    }
    else    {
        for(int i = 2 ; i < N ; ++i)
            exp = 1ll * exp * (c[i] + 1) % (mod - 1),
            c[i] /= 2;
    }
 
    int ans = 1;
 
    for(int i = 1 ; i < N ; ++i)
        ans = mul(ans,Pow(i,c[i]));
 
    cout << Pow(ans,exp);
}