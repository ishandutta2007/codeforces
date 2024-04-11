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

std::vector<std::vector<ll> > CD(1000 , std::vector<ll>());
std::vector<std::vector<ll> > C(1000 , std::vector<ll>());

std::vector<std::vector<ll> > CSD(1000 , std::vector<ll>());

std::vector<std::vector<ll> > ru(1000 , std::vector<ll>());
std::vector<std::vector<ll> > rn(1000 , std::vector<ll>());
std::vector<std::vector<ll> > cu(1000 , std::vector<ll>());
std::vector<std::vector<ll> > cn(1000 , std::vector<ll>());

bool cpass(ll i, ll j){

if(i < 0 || j < 0 || i >= n || j >= m){

    return 0;

}

else{
    return C[i][j];

}

}

int main()
{
    ll c1,c2,c3,c4,c5;
    ll a,b,c,d,e,f;
    ll x,y,z;
    ll q;

    string s;

    std:cin >> n >> m;

    for(c1=0;c1<n;c1++){

        std::cin >> s;
        for(c2=0;c2<m;c2++){

            if(s[c2] == '.'){C[c1].push_back(1);}
            else{C[c1].push_back(0);}
            CD[c1].push_back(0);
        }

    }

    for(c1=0;c1<n;c1++){
            CSD[c1].push_back(0);
        for(c2=0;c2<m;c2++){
            if(cpass(c1,c2) == 1){
                CD[c1][c2] = cpass(c1-1,c2) + cpass(c1+1,c2) +cpass(c1,c2-1) +cpass(c1,c2+1);
            }
            else{
                CD[c1][c2] = 0;
            }

            CSD[c1].push_back(CSD[c1][c2] + CD[c1][c2]);
        }
    }

    for(c1=0;c1<n;c1++){

        ru[c1].push_back(0);
        rn[c1].push_back(0);

        for(c2=0;c2<m;c2++){
            if(cpass(c1-1,c2) == 1 && cpass(c1,c2) == 1){
                ru[c1].push_back(ru[c1][c2]+1);
            }
            else{
                ru[c1].push_back(ru[c1][c2]);
            }

           // std::cout << ru[c1][c2+1] << " ";
            if(cpass(c1+1,c2) == 1 && cpass(c1,c2) == 1){
                rn[c1].push_back(rn[c1][c2]+1);
            }
            else{
                rn[c1].push_back(rn[c1][c2]);
            }
        }//std::cout << "\n";

    }

    for(c1=0;c1<m;c1++){

        cu[c1].push_back(0);
        cn[c1].push_back(0);

        for(c2=0;c2<n;c2++){
            if(cpass(c2,c1-1) == 1 && cpass(c2,c1) == 1){
                cu[c1].push_back(cu[c1][c2]+1);
            }
            else{cu[c1].push_back(cu[c1][c2]);}
            if(cpass(c2,c1+1) == 1 && cpass(c2,c1) == 1){
                cn[c1].push_back(cn[c1][c2]+1);
            }
            else{cn[c1].push_back(cn[c1][c2]);}
        }

    }


    std::cin >> q;
    ll disp;
    ll ans;
    for(c1=0;c1<q;c1++){

        std::cin >> a >> b >> c >> d;
        a--;
        b--;
        c--;
        d--;

        ans = 0;

        for(c2=a;c2<=c;c2++){
            ans += CSD[c2][d+1] - CSD[c2][b];
        }

        disp = 0;

        disp += ru[a][d+1] - ru[a][b];
        disp += rn[c][d+1] - rn[c][b];

        disp += cu[b][c+1] - cu[b][a];
        disp += cn[d][c+1] - cn[d][a];


        /*
        // 1
        c3 = b;
        for(c2 = a; c2 <= c; c2++){
            if(cpass(c2,c3) == 1 && cpass(c2,c3-1) == 1){
                disp++;
            }
        }

        // 2
        c3 = c;
        for(c2 = b; c2 <= d; c2++){
            if(cpass(c3,c2) == 1 && cpass(c3+1,c2) == 1){
                disp++;
            }
        }

        // 3
        c3 = d;
        for(c2 = c; c2 >= a; c2--){
            if(cpass(c2,c3) == 1 && cpass(c2,c3+1) == 1){
                disp++;
            }
        }

        // 4
        c3 = a;
        for(c2 = d; c2 >= b; c2--){
            if(cpass(c3,c2) == 1 && cpass(c3-1,c2) == 1){
                disp++;
            }
        }
        */
        ans -= disp;
        ans /= 2;
        std::cout << ans << "\n";

    }






	return 0;
}