#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <unordered_map>
#include <vector>
#include <queue>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <cstring>
#include <random>
#include <chrono>
#include <bitset>
#include <fstream>
#include <sstream>

using namespace std;

typedef long long ll;
typedef long double ld;

ll big = 1000000007ll;
float likeabutterfly;
string likeabee;
ll n,m,q,h,k,w;
ll T;

vector<ll> A;
vector<ll> B;

vector<ll> L;
vector<ll> R;
vector<ll> MA;

int main()
{
    ll c1,c2,c3,c4,c5,c6;
    ll a,b,d,e,c;
    ll x,y,z;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin >> n;
    for(c1 = 0; c1 < n; c1++){
        cin >> a;
        A.push_back(a);
    }
    cin >> m;
    for(c1 = 0; c1 < m; c1++){
        cin >> a;
        B.push_back(a);
    }

    ll l = 0;
    bool fail = 0;
    for(c1 = 0; c1 < m; c1++){
        ll l2 = l;
        bool dist = 0;
        ll su = 0;
        ll prev = -1;
        ll mags = 0;
        ll mind = 0;
        while(1 == 1){
            if(prev != -1 && A[l] != prev)dist = 1;
            prev = A[l];
            su += A[l];
            if(A[l] > mags){
                mags = A[l];
                mind = l;
            }
            l++;
            if(l == n)break;
            if(su >= B[c1])break;
        }

        //cout << su << " " << l2 << " - " << l-1 << "\n";

        if(su != B[c1])fail = 1;
        if(dist == 0 && l-1 != l2)fail = 1;
        if(l == n && c1 != m-1)fail = 1;
        if(fail == 1)break;

        L.push_back(l2);
        R.push_back(l-1);
        MA.push_back(mags);

    }

    if(l != n)fail = 1;

   if(fail == 1){

    cout << "NO\n";

   }
   else{

    cout << "YES\n";

    for(c1 = 0; c1 < m; c1++){

        ll nowind = 0;
        ll firstdir = 0;

        if(L[c1] != R[c1]){

        for(c2 = L[c1]; c2 <= R[c1]; c2++){
            if(A[c2] == MA[c1]){

                if(c2 > L[c1]){
                    if(A[c2-1] != MA[c1]){
                        firstdir = -1;
                        nowind = c2;
                        break;
                    }
                }

                if(c2 < R[c1]){
                    if(A[c2+1] != MA[c1]){
                        firstdir = 1;
                        nowind = c2;
                        break;
                    }
                }
            }
            }


        nowind-=L[c1];

        if(firstdir == -1){
            cout << nowind+1+c1 << " L\n";
            nowind--;
        }
        else{
            cout << nowind+1+c1 << " R\n";
        }

        for(c2 = L[c1]; c2 < R[c1]-1; c2++){

            if(nowind > 0){
                cout << nowind+1+c1 << " L\n";
                nowind--;
            }
            else{
                cout << nowind+1+c1 << " R\n";
            }
        }
        }
    }

   }


	return 0;
}