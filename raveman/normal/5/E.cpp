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

int n;
int a[2111111];
ll res;
vector<pii> v;

void solve(int p1,int p2){
    v.clear();
    v.pb(pii(a[p1],1));
    for(int i=p1+1;i<=p2;i++){

        if(i==p2 && p2==p1+n){
            int num  = 0;
            FOR(j,2,v.size()) num+=v[j].second;
            res+=max(0,num);
            res++;
            break;
        }

        while(a[i]>v.back().first){
            res+=v.back().second;
            v.pop_back();
        }

        if(a[i]<v.back().first){
            res++;
            v.pb(pii(a[i],1));
        }else if(a[i]==v.back().first){
            if(i==p2){
                res++;
                break;
            }
            res+=v.back().second+1;
            v.back().second++;            
        }
    }    
}

bool good(int i1,int i2){
    bool g1=true,g2=true;

    for(int i = min(i1,i2)+1;i<max(i1,i2);i++)
        if(a[i]>a[i1] || a[i]>a[i2]) g1=false;
   
    for(int i = max(i1,i2)+1;i<min(i1,i2)+n;i++)
        if(a[i]>a[i1] || a[i]>a[i2]) g2=false;
   
    return g1||g2;
}
int stupid(){
    int res =0 ;
    REP(i,n)REP(j,i)
        if(good(i,j)) res++;
    return res;
}

int main(){ 
#ifdef LocalHost
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

    cin>>n;
    int mx = -1;
    ll nm=0;
    REP(i,n) scanf("%d",a+i),a[i+n]=a[i],mx=max(mx,a[i]);
    REP(i,n)if(a[i]==mx) nm++;
    res= nm*(nm-1)/2;
    int p1 =0,p2;
    while(a[p1]!=mx) p1++;
    while(p1<n){
        p2=p1+1;
        while(a[p2]!=mx) p2++;

        solve(p1,p2);res--;

        p1++;
        while(a[p1]!=mx) p1++;
    }
    cout<<res<<endl;
//    cout<<stupid()<<endl;
    
    return 0;
}