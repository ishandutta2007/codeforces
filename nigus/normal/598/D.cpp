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

ll n,m,k;
std::vector<string> S;

std::vector<ll> pek;
std::vector<ll> len;
std::vector<ll> num;

ll dsupar(ll i)
{
    ll i2=i;
    while(pek[i2] != i2){i2=pek[i2];}return i2;
}

void dmerge(ll i2, ll j2)
{
    ll temp;
    ll i=i2;
    ll j=j2;
    if(dsupar(i) != dsupar(j)){

    if(len[dsupar(i)] < len[dsupar(j)])
    {
        temp = j;
        j=i;
        i=temp;
    }

    len[dsupar(i)] += len[dsupar(j)];
    num[dsupar(i)] += num[dsupar(j)];
    pek[dsupar(j)] = dsupar(i);
    pek[i]= dsupar(i);
    pek[j]=dsupar(i);
    }
    return;

}


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
    string s;
   std::cin >> n >> m >> k;

 for(c1=0;c1<n*m;c1++)
 {
     pek.push_back(c1);
     len.push_back(1);
     num.push_back(0);
 }

   for(c1 = 0; c1<n;c1++)
   {

       std::cin >> s;
       S.push_back(s);

   }
   char nu,nu2;
   ll a1,a2,a3,a4;
   ll b1,b2,b3,b4;
   for(c1=0;c1<n;c1++)
   {

       for(c2=0;c2<m;c2++)
       {

           nu = S[c1][c2];
           if(nu == '.')
           {

               a1=c1-1;b1=c2;
               a2=c1+1;b2=c2;
               a3=c1;b3=c2-1;
               a4=c1;b4=c2+1;

               if(a1 >= 0 && a1 < n && b1 >= 0 && b1 < m)
               {
                   nu2 = S[a1][b1];
                   if(nu2 == '.'){dmerge(c2+m*c1 , b1+m*a1);}
                   else{num[dsupar(c2+m*c1)]++;}
               }

               if(a2 >= 0 && a2 < n && b2 >= 0 && b2 < m)
               {
                   nu2 = S[a2][b2];
                   if(nu2 == '.'){dmerge(c2+m*c1 , b2+m*a2);}
                   else{num[dsupar(c2+m*c1)]++;}
               }

               if(a3 >= 0 && a3 < n && b3 >= 0 && b3 < m)
               {
                   nu2 = S[a3][b3];
                   if(nu2 == '.'){dmerge(c2+m*c1 , b3+m*a3);}
                   else{num[dsupar(c2+m*c1)]++;}
               }

               if(a4 >= 0 && a4 < n && b4 >= 0 && b4 < m)
               {
                   nu2 = S[a4][b4];
                   if(nu2 == '.'){dmerge(c2+m*c1 , b4+m*a4);}
                   else{num[dsupar(c2+m*c1)]++;}
               }

           }

       }

   }


   for(c1=0;c1<k;c1++)
   {

       std::cin >> a >> b;
       a--;
       b--;
       std::cout << num[dsupar(b+a*m)] << "\n";

   }



    return 0;
}