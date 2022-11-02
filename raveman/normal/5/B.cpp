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

vector<string> v;
string s;

int main(){ 
#ifdef LocalHost
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

    int mx = 0;
    while(getline(cin,s)) v.pb(s),mx=max(mx,int(s.size()));

    bool a = 0;
    REP(i,mx+2) printf("*");puts("");
    REP(i,v.size()){
        printf("*");

        int len = v[i].size();
        int l1 = mx-len;
        if(l1&1){
            l1+=a;
            a=!a;
        }
        l1/=2;
        int l2 =mx-len-l1;
        REP(j,l1) printf(" ");
        cout<<v[i];
        REP(j,l2) printf(" ");
        printf("*");
        puts("");
    }
    REP(i,mx+2) printf("*");puts("");

    
    
    return 0;
}