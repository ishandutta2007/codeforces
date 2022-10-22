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
#include <locale>
#include <sstream>


using namespace std;
typedef long long ll;
typedef long double ld;

ll big = 1000000007ll;
ll bp = 1168195727ll;
ll n,m,q;

string s;

std::vector<ll> F;
std::vector<ll> U;
ll nu;
ll l;
string nts (ll x)
  {
     ostringstream ss;
     ss << x;
     return ss.str();
  }

ll ctn(char ch)
{

    return ll(ch)-97;


}

char ntc (ll c)
{

    return char(c+97);

}
int main()
{
    ll c1,c2,c3,c4,c5,c6;
    ll a,b,q,c,d,x,f,t,l,r;
    std::cin >> s;
    l = s.length();
    nu=0;
    for(c1=0;c1<26;c1++)
    {

        F.push_back(0);

    }

    for(c1=0;c1<l;c1++)
    {
        F[ctn(s[c1])]++;
    }

    for(c1=0;c1<26;c1++)
    {

        if(F[c1] % 2 == 1)
        {
            U.push_back(c1);
            nu++;
        }

    }

    if(nu!=1){
    for(c1 = nu-1 ; 2*c1 >= nu ; c1--)
    {

        F[U[c1]]--;

    }

    for(c1 = 0 ; c1 < nu/2 ; c1++)
    {

        F[U[c1]]++;

    }}

    string ans ="";
    char skrap;
    bool fail=1;
    for(c1=0;c1<26;c1++)
    {

        for(c2=0;c2<F[c1]/2;c2++)
        {
            ans += ntc(c1);
        }

        if(F[c1]%2 == 1){skrap= ntc(c1);fail=0;}

    }
    if(fail==0){
    ans+=skrap;}
    for(c1=25;c1>=0;c1--)
    {

        for(c2=0;c2<F[c1]/2;c2++)
        {
            ans += ntc(c1);
        }



    }

std::cout << ans << "\n";

    return 0;
}