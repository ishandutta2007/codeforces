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

int n;
int c[2222];
int t[2222];
ll d[5222];
int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

    cin>>n;
    REP(i,n) scanf("%d %d",t+i,c+i),t[i]++;

    ll inf = 1000000000000000000ll;
    
    REP(i,5222) d[i] = inf;
    d[0] = 0;
    REP(i,n){
        for(int j = 5000;j>=0;j--) if(d[j]!=inf && j+t[i]<=5000) 
            if(d[j+t[i]] > d[j] + c[i])
                d[j+t[i]] = d[j] + c[i];
    }

    ll pay = inf;
    for(int j=n;j<=5000;j++)
        pay = min(pay,d[j]);
    cout<<pay<<endl;


    return 0;
}