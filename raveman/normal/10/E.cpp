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

int n;
int a[444];
int u[444];

int main(){    
#ifdef LocalHost
    freopen("input.txt","r",stdin);
#endif

    cin>>n;
    REP(i,n) cin>>a[i];

    int best = -1;
    FOR(i,1,n) FOR(j,i,n){
        int s = a[i-1]-1,s2=0;
        CL(u,0);
        int cc=0;
        REP(k,j+1) while(s>=a[k]) u[k]++,s-=a[k],cc++,s2+=a[k];
        u[j]++;cc++;s2+=a[j];
        if(best!=-1 && best<=s2) continue;
        int tt =s2;
        REP(k,n) while(s2>=a[k]) s2-=a[k],cc--;
        if(cc<0)if(best==-1 || best>tt) best=tt;
    }
    cout<<best<<endl;
    
    
    return 0;
}