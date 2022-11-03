#pragma comment(linker, "/STACK:36777216")

#include <algorithm>
#include <iostream>
#include<stdio.h>
#include <string>
#include<sstream>   
#include<string.h>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>
#include<memory.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<int,pii> p3i;
typedef long double ld;
typedef vector<ld> vd;

#define FOR(i,a,b) for (int i(a); i < (b); i++) 
#define REP(i,n) FOR(i,0,n) 
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define SORT(a) sort((a).begin(),(a).end())

int n,m;
int x[2],y[2];

ll st(ll x,ll m){
    ll r =0;
    REP(i,m) r^=(x+i);
    return r;
}

ll getX(ll n){
    ll res = 0;
    REP(i,18){
        ll temp = (n>>(i+1));

        bool p = false;

        if(i==0 && (temp&1)) p^=1;

        if(n&(1ll<<i)){
            ll val = n^(temp<<(i+1));
            val^=(1ll<<i);
            val++;
            if(val&1) p^=1;
        }


        if(p) res|=(1ll<<i);
    }
    return res;
}

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
#endif

 
  
    int n;
    cin>>n;
    ll xor = 0;
    REP(i,n){
        ll x,m;
        scanf("%lld %lld",&x,&m);
        xor ^= getX(x+m-1);
        xor ^= getX(x-1);
    }
    if(xor) puts("tolik");
    else puts("bolik");

    return 0;
}