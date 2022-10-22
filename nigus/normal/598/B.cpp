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

ll big = 1000000007ll;
ll bp = 1168195727ll;

ll n,m,k;
string s;


string nts (ll x)
  {
     ostringstream ss;
     ss << x;
     return ss.str();
  }



int main()
{
    ll c1,c2,c3,c4,c5,c6;
    ll a,b,p,q;

    ll l,r,L;

    std::cin >> s;
    std::cin >> m;
    string temp;
    for(c1=0;c1<m;c1++)
    {

        std::cin >> l >> r >> k;
        r--;
        l--;
        L = r-l+1;
        temp = s;
        for(c2=l; c2 <= r; c2++)
        {
            a = (c2-l-k+1000000*L)%L + l;
            s[c2]=temp[a];

        }

    }

std::cout << s;
    return 0;
}