#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <string>
#include <iomanip>

using namespace std;
typedef long long ll;

ll big = 1000000007ll;
ll bp = 1168195727ll;

std::vector<ll> P;
std::vector<bool> mark;
std::vector<ll> deg;
std::vector<ll> start;
ll nc;
void dfs(ll c){

    ll c2=c;
    ll L=0;
    L++;
    mark[c] = 1;
    while(P[c2] != c)
    {

        c2=P[c2];
        L++;
        mark[c2] = 1;


    }
deg.push_back(L);
start.push_back(c);
nc++;

return;
}

int main()
{
    ll c1,c2,c3,c4,c5,c6;

    ll T;
    ll a,b;
    ll n;
    ll x,y,z,w;

    std::cin >> n;
    for(c1=0;c1<n;c1++)
    {
        std::cin >> a;
        P.push_back(a-1);
        mark.push_back(0);

    }

    bool fail=1;
    ll ans;
    for(c1=0;c1<n;c1++){

        if(P[c1] == c1)
        {
            fail=0;
            ans=c1;
            break;
        }


    }

    if(fail==0)
    {

        std::cout << "YES\n";
        for(c1=0;c1<n;c1++)
        {
            if(c1!=ans){
            std::cout << ans+1 << " " << c1+1 << "\n";
            }

        }



    }

    else
    {
        nc=0;
        for(c1=0;c1<n;c1++)
        {

        if(mark[c1] == 0)
        {

        dfs(c1);
        }

        }

        fail=0;
        ll to=-1;

        for(c1=0;c1<nc;c1++)
        {

            if(deg[c1]%2==1){fail=1;}
            if(deg[c1]==2){to=c1;}


        }

        if(fail==0 && to!=-1)
        {

            std::cout << "YES\n";

            a=start[to];
            b=P[start[to]];

            std::cout << a+1 << " " << b+1 << "\n";

            for(c1=0;c1<nc;c1++)
            {

                if(c1 != to)
                {

                    x=start[c1];
                    y=P[x];
                    for(c2=0;c2<deg[c1];c2+=2)
                    {

                        std::cout << a+1 << " " << x+1 << "\n";
                        std::cout << b+1 << " " << y+1 << "\n";
                        x=P[y];
                        y=P[x];

                    }

                }

            }


        }

        else{

            std::cout << "NO\n";
        }


    }


    return 0;
}