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
ll n,m,k,q;
ll T;
std::vector<ll> A;
std::set<ll> S;
std::map<ll,ll> M;
std::vector<ll> ANS;

int main()
{
    ll c1,c2,c3,c4,c5;
    ll x,y,z;
    ll a,b,c,d,e,f;
    //freopen("test_input.txt","r",stdin);
    //freopen("output.txt","w",stdout);


    std::cin >> n;
    ll a1,a2;
    ll ma = 0;
    ll n2 = 0;
    for(c1=0;c1<n;c1++){
        std::cin >> a;
        //A.push_back(a);
        if(S.find(a) == S.end()){M[a] = 1;S.insert(a);}else{M[a]++;}
        if(M[a] <= 2){n2++;A.push_back(a);}
        ANS.push_back(0);
    }

    for(c1=0;c1<n2;c1++){
        for(c2=0;c2<n2;c2++){
            if(c1!=c2){
                a = A[c1];
                b = A[c2];
                ll matemp = 2;
                std::map<ll,ll> M2;
                std::set<ll> S2;
                S2.clear();
                M2.clear();
               // std::cout << a << " " << b << " " << a+b << "\n";
                M2[a+b] = 1;
                S2.insert(a+b);
                if(S2.find(a) != S2.end()){M2[a]++;}else{M2[a] = 1;S2.insert(a);}
                if(S2.find(b) != S2.end()){M2[b]++;}else{M2[b] = 1;S2.insert(b);}
                while(S.find(a+b) != S.end()){
                    if(M[a+b] >= M2[a+b]){
                        c = b;
                        b = a+b;
                        a = c;
                        if(S2.find(a+b) != S2.end()){M2[a+b]++;}else{M2[a+b] = 1;S2.insert(a+b);}
                        matemp++;
                    }
                    else{break;}
                }
                if(matemp > ma){ma = matemp; a1 = c1; a2 = c2;}
            }
        }
    }

    std::cout << ma << "\n";




	return 0;
}