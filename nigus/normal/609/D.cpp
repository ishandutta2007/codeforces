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
ll big = 1000000007ll;

std::vector<ll> dollar;
std::vector<ll> pound;
std::vector<ll> gd;
std::vector<ll> gp;
std::vector<ll> csd;
std::vector<ll> csp;
std::vector<ll> md;
std::vector<ll> mp;
std::vector<ll> mdi;
std::vector<ll> mpi;

std::vector<ll> ind1;
std::vector<ll> ind2;
std::vector<ll> dumind1;
std::vector<ll> dumind2;
ll nd,np;
ll n;
ll s,k;
ll a1,a2;

bool comp1(ll i, ll j){
return gd[i]<gd[j];
}
bool comp2(ll i, ll j){
return gp[i]<gp[j];
}
ll eva(ll i){
    ll mid = md[i];
    ll mip = mp[i];
    ll mi=999999999999999ll;
    if(nd+np < k){return mi;}
    ll a;
    for(ll c=0;c<=k;c++){
        if(c<=nd && k-c<=np){
        a = csd[c]*mid + csp[k-c]*mip;
        if(a<mi){mi=a;a1=c;a2=k-c;}}
        //if(i==i){cout <<i << "   "<< mi << " " <<csp[k-c] <<" "<< csd[c] << "\n";}
    }
return mi;
}

int main()
{

    ll m,x,y,z,c;
    ll c1,c2,c3,c4,c5,c6;
    ll a,b,d,e,f;
    std::cin >> n >> m >> k >> s;

    for(c1=0;c1<n;c1++)
    {
        std::cin >> a;
        dollar.push_back(a);
    }
    for(c1=0;c1<n;c1++)
    {
        std::cin >> a;
        pound.push_back(a);
    }
    nd=0;
    np=0;

    for(c1=0;c1<m;c1++)
    {

        std::cin >> a >> b;
        if(a==1){
            nd++;
            gd.push_back(b);
            ind1.push_back(nd-1);
            dumind1.push_back(c1);
        }
        else{
            np++;
            gp.push_back(b);
            ind2.push_back(np-1);
            dumind2.push_back(c1);
        }
    }
    std::sort(ind1.begin(),ind1.end(),comp1);
    std::sort(ind2.begin(),ind2.end(),comp2);
    std::sort(gd.begin(),gd.end());
    std::sort(gp.begin(),gp.end());
    csd.push_back(0);
    csp.push_back(0);
    for(c1=0;c1<nd;c1++){
        csd.push_back(gd[c1]+csd[c1]);
    }
    for(c1=0;c1<np;c1++){
        csp.push_back(gp[c1]+csp[c1]);
    }




    for(c1=0;c1<n;c1++)
    {

        if(c1==0){
            md.push_back(dollar[0]);
            mp.push_back(pound[0]);
            mdi.push_back(0);
            mpi.push_back(0);
        }
        else{
                if(dollar[c1]<md[c1-1]){mdi.push_back(c1);}
                else{mdi.push_back(mdi[c1-1]);}
                if(pound[c1]<mp[c1-1]){mpi.push_back(c1);}
                else{mpi.push_back(mpi[c1-1]);}
            md.push_back(min(dollar[c1] , md[c1-1]));
            mp.push_back(min(pound[c1] , mp[c1-1]));

        }

    }
/*
    for(c1=0;c1<n;c1++){
        std::cout << mdi[c1] << "-" << mpi[c1] << "\n";

    }
*/

    bool fail=false;
    bool noll = false;
     a=0;
     b=n-1;
    if(eva(b)>s){fail=1;}
    if(eva(0)<=s){noll = true;b=0;}
    else{
    while(a+1<b){

        c = (a+b)/2;
        d = eva(c);
        if(d<=s){b=c;}
        else{a=c;}

    }
    }
    if(fail==1){std::cout << -1 << "\n";}
    else{

        std::cout << b+1 << "\n";
        eva(b);
        for(c1=0;c1<a1;c1++){

            std::cout << dumind1[ind1[c1]]+1 << " " << mdi[b]+1 << "\n";

        }

        for(c1=0;c1<a2;c1++){

            std::cout << dumind2[ind2[c1]]+1 << " " << mpi[b]+1 << "\n";

        }



    }

	return 0;
}