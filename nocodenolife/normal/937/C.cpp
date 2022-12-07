#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
int main()
{
    ll k,d,t;
    cin>>k>>d>>t;
    ll tocook = 2*t;
    
    ll on = k;
    ll off = d - k%d;
    if(off == d)
        off =0;
    
    long double answer = 0;
    ll cooked = on*2 + off;
    ll rounds = tocook/cooked;
    tocook -= cooked*rounds;
    answer += rounds*(on+off);
    
    if(tocook>=2*on)
    {
        answer+=on;
        tocook-=2*on;
        answer+=tocook;
    }
    else
    {
        answer+= tocook/2.0;
    }
    
    cout<< fixed << setprecision(19)<<answer<<endl;
    
    return 0;
}