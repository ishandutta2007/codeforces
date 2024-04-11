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
int n,m,q,h,k,w;
ll T;


int F[300000] = {0};
int M[300000] = {0};
vector<int> A;

vector<vector<ll> > C(300000 , vector<ll>());

int main()
{
    ll c1,c2,c3,c4,c5,c6;
    int a,b,c,e,g;
    ll y,z;
    //freopen("stupd.txt","r",stdin);
    //freopen("output.txt","w",stdout);

   scanf("%d %d" , &n, &q);

   int tmax = 0;

   int ans = 0;
   c2 = 0;
   for(c3 = 0 ;c3 < q; c3++){
    scanf("%d %d" , &a, &b);

    if(a == 1){
        b--;
        F[b]++;
        ans++;
        A.push_back(b);
        C[b].push_back(c2);
        c2++;
    }
    if(a == 2){
        b--;
        ans -= F[b];
        F[b] = 0;
        M[b] = 0;
        C[b].clear();
    }
    if(a == 3 && b > tmax){


        for(c5 = tmax; c5 < b; c5++){

            c1 = A[c5];
            if(M[c1] < C[c1].size()){
                if(C[c1][M[c1]] == c5){
                    M[c1]++;
                    F[c1]--;
                    ans--;
                }
            }

        }

        tmax = b;

    }

    printf("%d\n" , ans);


   // cout << "m1: " << M[0] << "\n";

   }


	return 0;
}