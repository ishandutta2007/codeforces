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


int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif
    int n,k;
    cin>>n>>k;
    int num =0 ;
    vi pr;
    FOR(i,2,n+1){
        bool p = true;
        for(int j=2;j*j<=i;j++)if((i%j)==0){p=false;break;}
        if(p){
            bool g = false;
            FOR(j,1,pr.size())
                if(pr[j]+pr[j-1]+1==i) g=true;
            if(g) num++;
            pr.pb(i);
        }
    }
    puts((num>=k?"YES":"NO"));

   
    return 0;
}