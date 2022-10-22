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



int m,n;

ll gcd(ll a, ll b)
{

    if(b==0){return a;}
    return gcd(b,a%b);

}
std::vector<ll> S;

std::map<ll,ll> M;

int main()
{
    ll c1,c2,c3,c4,c5,c6;
    int a,b;

    std::cin >> n;
    std::vector<ll> A;
    for(c1=0;c1<n*n;c1++)
    {


        std::cin >> a;
        A.push_back(a);

    }

    std::sort(A.begin(),A.end());


bool fail=0;
    ll ns=0;
    for(c1=n*n-1;c1>=0;c1--)
    {
        fail=0;
        if(M.find(A[c1]) != M.end())
        {
            if(M[A[c1]] > 0){M[A[c1]]--;fail=1;}
        }

        if(fail==0)
        {

            for(c2=0;c2<ns;c2++)
            {

                b=gcd(S[c2],A[c1]);
                if(M.find(b) == M.end()){M[b] = 2;}
                else{M[b]+=2;}

            }
            S.push_back(A[c1]);
            ns++;

        }


    }


    for(c1=0;c1<n;c1++)
    {

        std::cout << S[c1] << " ";


    }


    return 0;
}