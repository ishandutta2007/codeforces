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

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<int,pii> p3i;

#define FOR(i,a,b) for (int i(a); i < (b); i++) 
#define REP(i,n) FOR(i,0,n) 
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define SORT(a) sort((a).begin(),(a).end())

int nb(int mask){return mask==0?0:1+nb(mask&(mask-1));}

ll gcd(ll a, ll b){
    if(a<0) a=-a;
    if(b<0) b=-b;
    while(a&&b)
        if(a>b) a%=b;
        else b%=a;
    return a+b;
}

typedef pair<ll,ll> pl;
pl gcd_ext(ll a,ll b){
    if(b==0) return pl(1,0);
    if(a>=b){
        pl res = gcd_ext(b,a%b);


        ll y1,y2;ll x1 = res.first;ll x2 =res.second;

        y1 = x2;
        y2 = x1 - (a/b)*x2;

        return pl(y1,y2);
    }else{
        pl t = gcd_ext(b,a);
        swap(t.first,t.second);
        return t;

    }
}

int main(){ 
#ifdef LocalHost
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

    ll a,b,c;
    cin>>a>>b>>c;

    ll d = gcd(a,b);
    
    a/=d;b/=d;
    if(c%d) puts("-1");
    else{
        c/=d;
        pl res = gcd_ext(a<0?-a:a,b<0?-b:b);

        ll x1,x2;
        x1=res.first;
        x2=res.second;
        if(a<0) x1*=(-1);
        if(b<0) x2*=(-1);

        c=-c;
        x1*=c;x2*=c;
        cout<<x1<<' '<<x2<<endl;


    }
    
    

    

    return 0;
}