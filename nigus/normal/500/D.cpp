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
#include <stdio.h>

using namespace std;
typedef long long ll;
typedef long double ld;
ll big = 1000000007ll;
ll n,m,k;

std::vector<ll> ord;

std::vector<std::vector<ll> > C(200000 , std::vector<ll>());
std::vector<ll> A;
std::vector<ll> B;
std::vector<ll> W;

std::vector<std::vector<ll> > anod(200000 , std::vector<ll>());

std::vector<ll> deg;
std::vector<ll> kdeg;

std::vector<ll> mark;

ll nu;

std::vector<ld> coeff;

ll dfs(ll i){

ord[i]=nu;
nu++;
mark[i] = 1;
ll ans = 0;
ll a,b,c,d;
for(c=0;c < deg[i]; c++){

    a = anod[i][c];
    if(mark[a] == 0){
        ans += dfs(a);
    }
}
kdeg[i]=ans+1;
return ans+1;
}

int main()
{
    ll c1,c2,c3,c4,c5;
    ll a,b,c,d,e,f;
    ll x,y,z;
    ll q;

    std::cin >> n;
    //n = 10000;
    nu=0;
    for(c1=0;c1<n;c1++){
        ord.push_back(0);
        deg.push_back(0);
        mark.push_back(0);
        kdeg.push_back(0);
    }

    for(c1=0;c1<n-1;c1++){

        std::cin>> a>>b>>c;
        //a = c1+1;
        //b = c1+2;
        //c = 1000;
        a--;
        b--;
        A.push_back(a);
        B.push_back(b);
        W.push_back(c);
        deg[a]++;
        deg[b]++;
        anod[a].push_back(b);
        anod[b].push_back(a);

    }

    dfs(0);
    ld vv = 0.0;
    ll k1,k2;
    ld co,co2;
    ll n2 = n;
    for(c1=0;c1<n-1;c1++){

        a = A[c1];
        b = B[c1];
        //std::cout << "A:  " << A[c1] << "  B:  " << B[c1] << "   kdeg1:  " << kdeg[A[c1]] << "  kdeg2: " << kdeg[B[c1]] << "\n";
        if(ord[a] > ord[b]){

            k1 = kdeg[a];
            k2 = n-k1;
        }
        else{
            k1 = kdeg[b];
            k2 = n-k1;

        }
        //std::cout << "k1:  " << k1 << "  k2:  " << k2 << "\n";
        n2=n;
        co = 0;
        co2=0;
        if(k1 > 2){
        co += ld(k1)/ld(n2);
        n2--;
        k1--;
        co *= ld(k1)/ld(n2);
        n2--;
        k1--;
        co *= ld(k1)/ld(n2);
        }
        if(k2 > 2){
        n2 = n;
        co2 += ld(k2)/ld(n2);
        n2--;
        k2--;
        co2 *= ld(k2)/ld(n2);
        n2--;
        k2--;
        co2 *= ld(k2)/ld(n2);
        }
        co+=co2;
        co = 2.0 - 2.0*co;
        //cout <<"c:  "<< c1 << "  co:  "<< co<< "\n";
        coeff.push_back(co);
        vv += co * ld(W[c1]);
        //cout << "vv: " << vv << "\n";
    }

    std::cin >> q;
    //q = 10;
    for(c1=0;c1<q;c1++){

        std::cin >> a >> b;
        //a = c1+1;
        //b = 500;
        a--;
        vv -= coeff[a]*ld(W[a]-b);
        W[a] = b;
        std::cout <<std::setprecision(18)<< vv << "\n";
    }

	return 0;
}