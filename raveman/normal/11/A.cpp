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
typedef pair<pii,int> p3i;
typedef long double ld;
typedef vector<ld> vd;

#define FOR(i,a,b) for (int i(a); i < (b); i++) 
#define REP(i,n) FOR(i,0,n) 
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define SORT(a) sort((a).begin(),(a).end())

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

    int n,d;
    cin>>n>>d;
    ll res=0;
    ll last =0;
    REP(i,n){
        ll x;
        cin>>x;
        ll cc = 0;
        if(last+1> x ){
            cc = ((last+1) - x + d -1) /d;
        }
        res+=cc;
        x+=cc*d;
        last=x;
    }
    cout<<res<<endl;
    return 0;
}