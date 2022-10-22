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

std::vector<ll> S1;
std::vector<ll> S2;
std::vector<ll> f2;
std::vector<ll> f1;

std::vector<ll> prim;
ll np;

std::vector<ll> gp;

std::vector<std::vector<ll> > dp(2000002 , std::vector<ll>());
std::vector<ll> deg;

ll weird;
ll N;
ll g = 2000002ll;
void p1(ll x)
{

    //ll sq=ll(sqrt(x));

    ll c = 2ll;
    ll x2=x;


    if(deg[x] != 0)
    {

        for(c = 0; c<deg[x] ; c++)
        {

            S1[dp[x][c]]++;



        }

        return;
    }


    ll c4=0;
    c=prim[c4];
    while(c*c<=x)
    {

        if(x2%c==0){x2=x2/c;break;}
        else{c4++;}
        if(c4 < np){c=prim[c4];}else{c=c4;}


    }
    ll c2;
    if(x2==x){


            deg[x] = 1;dp[x].push_back(x);S1[x]++;
            prim.push_back(x);
            np++;
            //cout <<"fds    "<< x <<"\n";

    }

    else{

        deg[x]++;
        dp[x].push_back(c);
        S1[c]++;

        for(c2=0;c2<deg[x2];c2++)
        {
            deg[x]++;
            dp[x].push_back(dp[x2][c2]);
            S1[dp[x2][c2]]++;


        }

    }

    return;

}

void p2(ll x)
{

    //ll sq=ll(sqrt(x));


    ll x2=x;
    ll a;
    ll c;
    if(deg[x] != 0)
    {

        for(c = 0; c<deg[x] ; c++)
        {

            S2[dp[x][c]]++;
           // cout << x << " " << dp[x][c] << " " << S2[dp[x][c]] << "\n";

           a=dp[x][c]; if(S2[a] > S1[a]){gp[a] *= a; if(gp[a] > big){gp[a] %= big;}}

        }

        return;

    }
ll c4=0;
c=prim[c4];
    while(c*c<=x)
    {
        if(x2%c==0){x2=x2/c;break;}
        else{c4++;}
        if(c4 < np){c=prim[c4];}else{c=c4;}


    }
    ll c2;
    if(x2==x){




            deg[x] = 1;dp[x].push_back(x);S2[x]++;
            a=x; if(S2[a] > S1[a]){gp[a] *= a; if(gp[a] > big){gp[a] %= big;}}

            prim.push_back(x);
            np++;
            //cout <<"fds    "<< x <<"\n";

    }


    else{

        deg[x]++;
        dp[x].push_back(c);
         S2[c]++;
         a=c; if(S2[a] > S1[a]){gp[a] *= a; if(gp[a] > big){gp[a] %= big;}}
        for(c2=0;c2<deg[x2];c2++)
        {
            deg[x]++;
            dp[x].push_back(dp[x2][c2]);
            S2[dp[x2][c2]]++;
            a=dp[x2][c2]; if(S2[a] > S1[a]){gp[a] *= a; if(gp[a] > big){gp[a] %= big;}}

        }

    }

    return;

}



ll gcd(ll a,ll b)
{
    if(b==0){return a;}
    else{return gcd(b,a%b);}


}

ll bin(ll n)
{

ll y;
ll c1;
weird=1ll;
  for(c1=1;c1<n;c1++)
  {

    p1(c1+1);
  }
  std::sort(prim.begin(),prim.end());

  for(c1=n+1;c1<=2*n+1;c1++)
  {
        if(c1==n+1){y=2ll;}else{
      y=c1;

      }

      p2(y);


  }

  std::sort(prim.begin(),prim.end());
ll svar=1ll;
ll c2,c3;
//ll sq= round(sqrt(N)+1);
  for(c1=2;c1<g;c1++)
  {

      if(S2[c1] != 0){

        //cout << c1 << " " << S2[c1] << " " << S1[c1] << "\n";
        svar*=gp[c1];
        if(svar > big){svar %= big;}

      }


  }

svar *= weird;
svar %= big;

    return svar;




}



int main()
{
    ll c1,c2,c3,c4,c5,c6;

ll n;

for(c1=0;c1<g;c1++)
    {

        S1.push_back(0);
        S2.push_back(0);
        gp.push_back(1ll);
        deg.push_back(0);

    }
prim.push_back(2);
np=1;
 while(std::cin >> n){

    //n=1000000ll;

   N=n;
    for(c1=0;c1<g;c1++)
    {

        S1[c1] = 0;
        S2[c1] = 0;
        gp[c1] = 1ll;
        //deg[c1] = 0;

    }
  ll a;
  int ans;

    if(n==1){a=5;}
    else{
 a = bin(n);
 a--;}
 if(a==-1){a=big-1;}
 a%=big;

  ans = int(a);
  std::cout << ans << "\n";
 }
    return 0;
}