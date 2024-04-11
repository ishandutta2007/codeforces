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

string s[10];
int nb(int mask){return mask==0?0:1+nb(mask&(mask-1));}

int main(){ 
#ifdef LocalHost
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif
    REP(i,8) cin>>s[i];

    int mn = 20;
    REP(i1,1<<8)REP(i2,1<<8){
        bool good = true;
        REP(i,8)REP(j,8){
            bool b1 = s[i][j]=='B';
            bool b2 = (i1&(1<<i))|(i2&(1<<j));
            if(b1!=b2) good=false;
        }
        if(good)
            mn=min(mn,nb(i1)+nb(i2));
    }

    if(mn==20) cout<<-1<<endl;
    else cout<<mn<<endl;

    return 0;
}