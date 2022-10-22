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

std::vector<ll> deg;
std::vector<std::vector<ll> > C(200000 , std::vector<ll>());
std::vector<std::vector<ll> > B(200000 , std::vector<ll>());
std::vector<char> ANS;
std::vector<ll> mark;
std::vector<ll> mark2;
std::vector<ll> cl;
char nu;
void dfs(ll i){
    ANS[i] = nu;
    cl.push_back(i);
    for(ll c = 0; c<deg[i];c++){
        ll a = C[i][c];
        if(ANS[a] == 'd'){
            ANS[a]=nu;
            dfs(a);
        }
    }
    return;
}
int main()
{
    ll c1,c2,c3,c4,c5;
    ll x,y,z;
    ll a,b,c,d,e,f;
    //freopen("test_input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll ans = 0;
    std::cin >> n >> m;
    for(c1=0;c1<n;c1++){deg.push_back(0);ANS.push_back('d');mark.push_back(0);}
    for(c1=0;c1<n;c1++){
        for(c2=0;c2<n;c2++){
            B[c1].push_back(0);
        }
    }
    for(c1=0;c1<m;c1++){
        std::cin >> a >> b;
        a--;
        b--;
        deg[a]++;
        deg[b]++;
        C[a].push_back(b);
        C[b].push_back(a);
        B[a][b] = 1;
        B[b][a] = 1;
    }
    bool fail = 0;
    for(c1=0;c1<n;c1++){
        if(deg[c1] == n-1){
            ANS[c1] = 'b';
            mark[c1] = 1;
        }
    }
    ll cln;
    nu = 'a';
    for(c1=0;c1<n;c1++){
        if(ANS[c1] == 'd'){
            if(nu == 'd'){fail = 1;}
            cl.clear();
            dfs(c1);
            cln = cl.size();
            bool fail2 = 0;
            for(c2 = 0; c2<cln;c2++){
                for(c3 = c2+1;c3<cln;c3++){
                    a = cl[c2];
                    b = cl[c3];
                    if(B[a][b] == 0){fail = 1;break;}
                }
                //cout << cl[c2] << "  dsajd\n";
            }
            if(nu == 'c'){nu = 'd';}
            if(nu == 'a'){nu = 'c';}

        }
    }
    if(fail == 1){std::cout << "No\n";}
    else{
        std::cout << "Yes\n";
        for(c1=0;c1<n;c1++){
            std::cout << ANS[c1];
        }
    }
	return 0;
}