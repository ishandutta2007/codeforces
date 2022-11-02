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
typedef long double ld;
typedef vector<ld> vd;

#define FOR(i,a,b) for (int i(a); i < (b); i++) 
#define REP(i,n) FOR(i,0,n) 
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define SORT(a) sort((a).begin(),(a).end())

int l[111],r[111];

int main(){    
#ifdef LocalHost
    freopen("input.txt","r",stdin);
#endif

    ll n,p1,p2,p3,t1,t2;
    cin>>n>>p1>>p2>>p3>>t1>>t2;
    ll res=0;

    REP(i,n) cin>>l[i]>>r[i],res+=(r[i]-l[i])*p1;
    FOR(i,1,n){
        int t = l[i] - r[i-1];
        if(t<=t1){
            res+=t*p1;
        }else{
            res+=t1*p1;
            t-=t1;
            if(t<=t2){
                res+=t*p2;
            }else{
                res+=t2*p2;
                t-=t2;
                res+=t*p3;
            }
        }
    }

    
    cout<<res<<endl;

    return 0;
}