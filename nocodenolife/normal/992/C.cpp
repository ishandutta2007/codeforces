#include <bits/stdc++.h>
typedef long long int ll;
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define pair pair<int,int>
#define F first
#define S second
#define mem(x) memset(x,0,sizeof(x))
using namespace std;

ll powe(ll x, ll y, ll p)
{
    ll res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll x,k;
    cin>>x>>k;
    if(x==0)
    {
      cout<<"0"<<endl;
      return 0;
    }
    ll modder = 1000000007;
    ll answer = 2*x;
    answer = answer%modder;

    //finding 2^k
    ll power= powe(2,k,modder);

    answer = answer * power;
    answer -= (power-1);
    answer = answer%modder;
    while(answer<0)
    {
        answer+=modder;
    }
    cout<<answer<<endl;


    return 0;
}