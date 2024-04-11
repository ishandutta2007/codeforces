#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
    ll n,k,m,d;
    cin>>n>>k>>m>>d;
    
    ll g = (n/(m*k))*m;
    ll l = n - (g*k);
    if(l>=m)
        g+=m;
    
    ll answer = g;
    
    for(ll i=1;i<=d;i++)
    {
        ll candies1 = n/((i-1)*k+1);
        if(candies1<=0)
        {
            break;
        }
        if(candies1<=m && candies1>0)
        {
            ll rounds = n/(candies1*k);
            rounds += (n%(candies1*k)!=0);
            if(rounds<=d)
            {
                ll got =  (n/(candies1*k)) * candies1;
                ll left = n - (got*k);
                if(left>=candies1)
                    left = candies1;
                else
                    left = 0;
                got+=left;
                if(got>answer)
                    answer = got;
            }
        }
        candies1++;
        if(candies1<=m)
        {
            ll rounds = n/(candies1*k);
            rounds += (n%(candies1*k)!=0);
            if(rounds<=d)
            {
                ll got =  (n/(candies1*k)) * candies1;
                ll left = n - (got*k);
                if(left>=candies1)
                    left = candies1;
                else
                    left = 0;
                got+=left;
                if(got>answer)
                    answer = got;
            }
        }
        
    }
    cout<<answer<<endl;
    return 0;
}