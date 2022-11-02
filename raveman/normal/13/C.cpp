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


int a[5555];
ll d1[5555];
ll d2[5555];
const ll inf = 1000000000000000000ll;

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
#endif
    
    int n;
    cin>>n;
    vi v;
    REP(i,n) scanf("%d",a+i),v.pb(a[i]);
    UN(v);
    int m = v.size();
    REP(i,n) a[i]=lower_bound(v.begin(),v.end(),a[i])-v.begin();
    REP(q,n){
        REP(i,m) d2[i]=inf;
        REP(i,m){
            if(i) d2[i]=d2[i-1];
            d2[i]=min(d2[i],d1[i]+abs(v[a[q]]-v[i]));            
        }
        REP(i,m) d1[i]=d2[i];
    }
    ll res = inf;
    REP(i,m) res=min(res,d1[i]);
    cout<<res<<endl;

    return 0;
}