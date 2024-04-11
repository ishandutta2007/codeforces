#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

int main()
{
    vector<ll> gen;
    ll lim=4*1e9;
    for(int i=0;i<32;i++)
    {
        for(int j=0;j<32;j++)
        {
            int x=pow(2,i);
            int y=pow(3,j);
            gen.pb((ll)x*y);
        }
    }
    int l,r;
    int cnt=0;
    scanf("%i %i",&l,&r);
    for(auto p:gen)
    {
        if(p>=l&&p<=r)
        {
            cnt++;
        }
    }
    printf("%i\n",cnt);
    return 0;
}