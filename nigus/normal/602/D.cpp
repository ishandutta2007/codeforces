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
int n,m,q;
ll ans;
ll temp;

std::vector<ll> H;
std::vector<ll> D;
std::vector<ll> T;
std::vector<ll> ind;

std::vector<ll> L;
std::vector<ll> R;

string nts (ll x)
  {
     ostringstream ss;
     ss << x;
     return ss.str();
  }
bool comp(ll i, ll j)
{
    return D[i] > D[j];
}

int main()
{
    ll c1,c2,c3,c4,c5,c6;
    ll b,p,c,d,x,f,t;
    int a,l,r;
   // std::cin >> n >> q;
    scanf("%d %d" , &n, &q);

    std::set<ll>::iterator it;
    for(c1=0;c1<n;c1++)
    {
       // std::cin >> a;
        scanf("%d" , &a);
        H.push_back(a);
        if(c1>0)
        {
            D.push_back(abs(H[c1]-H[c1-1]));
            //std::cout << D[c1-1] << " ";
        }
        ind.push_back(c1);
        L.push_back(0);
        R.push_back(0);
    }

    D.push_back(0);
    std::sort(ind.begin(),ind.end(),comp);
    ll ans;

    std::set<ll> S;
        std::set<ll> S2;
        S.insert(-1);
        S.insert(n);

        S2.insert(1);
        S2.insert(-n);

    for(c2=0;c2<n;c2++)
        {

            p = ind[c2];


            it = S.upper_bound(p);
            b = *it;
            //std::cout << ind[c2] << "  " << b <<"    " << a<< "\n";
            R[p]=b;

            it = S2.upper_bound(-p);
            c = -(*it);
            //std::cout << ind[c2] << "  " << c <<"    " << a<< "\n\n";
            L[p]=c;
            S.insert(ind[c2]);
            S2.insert(-ind[c2]);


        }



    for(c1=0;c1<q;c1++)
    {

        //std::cin >> l >> r;
        scanf("%d %d" , &l , &r);
        l--;
        r-=2;
        ans = 0ll;


        for(c2=0;c2<n;c2++)
        {

            if(ind[c2] <= r && ind[c2] >= l)
            {

            p = ind[c2];
            a = D[ind[c2]];


            b = min(R[p]-p,r+1-p);
            c = min(p-L[p],p-l+1);


            temp=1ll;
            temp *= ll(a);
            temp *= ll(b);
            temp *= ll(c);
            ans += temp;


        }
        }
    ans = ll(ans);
        //printf("%\n" , ans);
    std::cout << ans << "\n";

    }


    return 0;
}