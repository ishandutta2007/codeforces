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
ll n,m,k,q,d;
ll T;

std::vector<ll> A;
std::vector<ll> A2;

std::vector<ll> B;

std::vector<ll> X;
std::vector<ll> Y;

std::vector<ll> mark;

int main()
{
    ll c1,c2,c3,c4,c5,c6;
    ll x,y,z;
    ll a,b,c,e;
    //freopen("test_input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    std::cin >> n;

    for(c1 = 0; c1 < n; c1++){
        std::cin >> a;
        A.push_back(a);
        A2.push_back(a);
        mark.push_back(0);
    }
    ll l = 0;
     for(c1 = 0; c1 < n-1; c1++){
        if(c1 % 2 == 0 && A[c1] >= A[c1+1]){
            X.push_back(c1);
            Y.push_back(c1+1);
            if(B.size() > 0){
            if(B[B.size()-1] != c1){B.push_back(c1);mark[c1] = 1;}}else{B.push_back(c1);mark[c1] = 1;}
            B.push_back(c1+1);
            mark[c1+1] = 1;
            l++;
        }
        if(c1 % 2 == 1 && A[c1] <= A[c1+1]){
            X.push_back(c1);
            Y.push_back(c1+1);
        if(B.size() > 0){
            if(B[B.size()-1] != c1){B.push_back(c1);mark[c1] = 1;}}else{B.push_back(c1);mark[c1] = 1;}
            B.push_back(c1+1);
            mark[c1+1] = 1;
            l++;
        }
    }

    if(B.size() > 10){
        std::cout << 0 << "\n";
    }
    else{

        ll ans = 0;
        for(c1 = 0; c1 < B.size(); c1++){

            a = B[c1];

            for(c2 = 0; c2 < n; c2++){

                if(c2 >= a && mark[c2] == 1){}
                else{

                    A2[a] = A[c2];
                    A2[c2] = A[a];
                    bool fail = 0;
                    for(c3 = 0; c3 < X.size(); c3++){
                        b = X[c3];
                        c = Y[c3];
                        if(X[c3] % 2 == 0 && A2[X[c3]] >= A2[Y[c3]]){fail = 1;}
                        if(X[c3] % 2 == 1 && A2[X[c3]] <= A2[Y[c3]]){fail = 1;}
                    }
                    if(c2 > 0){
                        if((c2-1) % 2 == 0 && A2[c2-1] >= A2[c2]){fail = 1;}
                        if((c2-1) % 2 == 1 && A2[c2-1] <= A2[c2]){fail = 1;}
                    }
                    if(c2 < n-1){
                        if((c2) % 2 == 0 && A2[c2] >= A2[c2+1]){fail = 1;}
                        if((c2) % 2 == 1 && A2[c2] <= A2[c2+1]){fail = 1;}
                    }
                    if(fail == 0){ans++; //cout << a << " " << c2 << "\n";
                    }
                    A2[a] = A[a];
                    A2[c2] = A[c2];
                }


            }


        }
        std::cout << ans << "\n";

    }



	return 0;
}