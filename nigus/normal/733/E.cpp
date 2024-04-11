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

vector<ll> CSL;
vector<ll> CSR;

vector<ll> NL;
vector<ll> NR;

ll totl = 0;
ll totr = 0;

int main()
{
    ll c1,c2,c3,c4,c5,c6;
    ll a,b,d,e,c;
    ll x,y,z;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    //scanf("%d" , &n);
    cin >> n;
    char s[1000001];
    scanf("%s", s);

    CSL.push_back(0);
    CSR.push_back(0);
    NL.push_back(0);
    NR.push_back(0);

    for(c1 = 0; c1 < n; c1++){
        NL.push_back(NL[c1]);
        NR.push_back(NR[c1]);

        if(s[c1] == 'U'){
            NL[c1+1]++;
            CSL.push_back(CSL[CSL.size() - 1] + n-c1);
        }
        else{
            NR[c1+1]++;
            CSR.push_back(CSR[CSR.size() - 1] + c1+1);
        }
    }

    for(c1 = 0; c1 < n; c1++){

        ll nr,nl;
        ll ans = 0;
        if(s[c1] == 'U'){

            nr = NR[n]-NR[c1+1];
            nl = NL[c1]-NL[0];

            ll mi = min(nr,nl);



            if(nl >= nr){

                ans += 2 * (CSL[nl] - CSL[nl-mi] - mi*(n-c1)) + 2 * (CSR[NR[c1+1]+mi] - CSR[NR[c1+1]] - mi*(c1+1)) + (n-c1);

            }
            else{

                ans += 2 * (CSL[nl] - CSL[nl-mi] - mi*(n-c1)) + 2 * (CSR[NR[c1+1]+mi+1] - CSR[NR[c1+1]] - (mi+1)*(c1+1)) + (c1+1);

            }

        }
        else{
            nr = NR[n]-NR[c1+1];
            nl = NL[c1]-NL[0];

            ll mi = min(nr,nl);

            if(nl > nr){

                ans += 2 * (CSL[nl] - CSL[nl-mi-1] - (mi+1)*(n-c1)) + 2 * (CSR[NR[c1+1]+mi] - CSR[NR[c1+1]] - mi*(c1+1)) + (n-c1);

            }
            else{

                ans += 2 * (CSL[nl] - CSL[nl-mi] - mi*(n-c1)) + 2 * (CSR[NR[c1+1]+mi] - CSR[NR[c1+1]] - mi*(c1+1)) + (c1+1);

            }
        }
        //cout << nl << " " << nr << "\n";
        cout << ans << " ";

    }

	return 0;
}