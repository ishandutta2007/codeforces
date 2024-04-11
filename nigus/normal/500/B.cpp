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
ll n,m,k;



std::vector<std::vector<ll> > C(3000 , std::vector<ll>());
ll cnn;
std::vector<ll> cn;
std::vector<std::vector<ll> > A(3000 , std::vector<ll>());
std::vector<ll> p;

std::vector<ll> pek;
std::vector<ll> deg;

std::vector<ll> ind;
std::vector<ll> mark;
std::vector<ll> mpek;

std::vector<ll> mpo;

ll par(ll i){
ll i2 = i;
while(i2 != pek[i2]){i2 = pek[i2];}
return i2;
}

void merg(ll i, ll j){

ll i2 = par(i);
ll j2 = par(j);

if(i2 != j2){
    if(deg[i2] > deg[j2]){
        deg[i2] += deg[j2];
        pek[j2] = i2;
    }

    else{
        deg[j2] += deg[i2];
        pek[i2] = j2;
    }

}
return;
}

bool comp(ll i , ll j){

return p[i] < p[j];
}

int main()
{
    ll c1,c2,c3,c4,c5;
    ll a,b,c,d,e,f;
    ll x,y,z;
    string s;

    std::cin >> n;
    for(c1=0;c1<n;c1++){

        std::cin >> a;
        p.push_back(a);
        deg.push_back(1);
        pek.push_back(c1);
        mark.push_back(0);
        mpek.push_back(0);
    }

    for(c1=0;c1<n;c1++){

        std::cin >> s;
        for(c2=0;c2<n;c2++){

            if(s[c2] == '0'){
                A[c1].push_back(0);
            }
            else{
                A[c1].push_back(1);
            }

        }

    }
    cnn  = 0;
    for(c1=0;c1<n;c1++){

        for(c2=0;c2<n;c2++){

            if(A[c1][c2] == 1){
                merg(c1,c2);
            }
        }

    }
    cnn=0;
    ll curr = 0;
    for(c1=0;c1<n;c1++){
        c2=par(c1);
        if(mark[c2] == 0){
            cnn++;
            cn.push_back(1);
            C[curr].push_back(c1);
            mpek[c2] = curr;
            curr++;
            mark[c2] = 1;
        }
        else{
            cn[mpek[c2]]++;
            C[mpek[c2]].push_back(c1);
        }

    }

    for(c1=0;c1<curr;c1++){
        std::sort(C[c1].begin(),C[c1].end(),comp);
        mpo.push_back(0);
    }

    for(c1=0;c1<n;c1++){

        c2 = mpek[par(c1)];
        std::cout << p[C[c2][mpo[c2]]] << " ";
        mpo[c2]++;

    }



	return 0;
}