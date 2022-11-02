#pragma comment(linker, "/STACK:836777216")

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

const int mod = 51123987;

char s1[1111111];
char s2[1111111];

ll qp(ll c,ll st,ll mod){
    ll r=1;
    while(st){
        if(st&1) r*=c,r%=mod;
        c*=c,c%=mod;
        st>>=1;
    }
    return r;
}
int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif
    int c;
    scanf(" %s %s %d",s1,s2,&c);
    ll x = 0;
    int q = strlen(s1);
    REP(i,q)
        x=10*x+s1[i]-'0',x%=c;
    ll b = x;
    ll b1 = (x-1+c)%c;


    int w= strlen(s2);
    s2[w-1]--;
    int pos = w-1;
    while(s2[pos]<'0'){
        s2[pos]+=10;
        pos--;
        s2[pos]--;
    }

    
    ll res = 1;
    ll t = b;
    for(int i = w-1;i>=0;i--){
        ll add = 1;
        REP(j,s2[i]-'0') add *= t,add%=c;

        res *= add,res%=c;


        ll tmp  = t;
        t=1;
        REP(j,10) t*=tmp,t%=c;
    }

    res*=b1;
    res%=c;

    if(res==0) cout<<c<<endl;
    else cout<<res<<endl;
    
    return 0;
}