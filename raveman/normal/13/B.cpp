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


pii b[3],e[3];

ll sq(pii p1,pii p2,pii p3){
    return ll(p2.first-p1.first)*ll(p3.second-p1.second)-ll(p3.first-p1.first)*ll(p2.second-p1.second);
}

ll dist(pii p1,pii p2){
    return ll(p1.first-p2.first)*ll(p1.first-p2.first)+ll(p1.second-p2.second)*ll(p1.second-p2.second);
}

bool good(int s1,int s2,int s3){
    if(b[s1]==b[s2]) swap(b[s1],e[s1]);
    if(b[s1]==e[s2]) swap(b[s1],e[s1]),swap(b[s2],e[s2]);
    if(e[s1]==b[s2]) {}
    if(e[s1]==e[s2]) swap(b[s2],e[s2]);
    if(e[s1]!=b[s2]) return false;

    if(sq(b[s1],e[s1],b[s3]))
        swap(b[s3],e[s3]);
    if(sq(b[s2],e[s2],e[s3]))
        swap(b[s3],e[s3]);

    if(sq(b[s1],e[s1],e[s2])==0) return false;
    if(sq(b[s2],e[s2],b[s1])==0) return false;


    if(sq(b[s1],e[s1],b[s3]))return false; 
    if(sq(b[s1],e[s1],e[s3])==0)return false; 
    if(sq(b[s2],e[s2],e[s3]))return false; 
    if(sq(b[s2],e[s2],b[s3])==0)return false; 

    if(b[s3].first<min(b[s1].first,e[s1].first)) return false;
    if(b[s3].first>max(b[s1].first,e[s1].first)) return false;
    
    if(b[s3].second<min(b[s1].second,e[s1].second)) return false;
    if(b[s3].second>max(b[s1].second,e[s1].second)) return false;
    

    if(e[s3].first<min(b[s2].first,e[s2].first)) return false;
    if(e[s3].first>max(b[s2].first,e[s2].first)) return false;
    
    if(e[s3].second<min(b[s2].second,e[s2].second)) return false;
    if(e[s3].second>max(b[s2].second,e[s2].second)) return false;


    
    if(dist(b[s1],e[s2])>dist(b[s1],e[s1])+dist(b[s2],e[s2])) return false;
    if(dist(b[s1],e[s2])==0) return false;


    ll d1 = dist(b[s1],b[s3]);
    ll d2 = dist(e[s1],b[s3]);
    if(d1>d2) swap(d1,d2);

    if(16*d1<d2) return false;

    d1 = dist(b[s2],e[s3]);
    d2 = dist(e[s2],e[s3]);
    if(d1>d2) swap(d1,d2);

    if(16*d1<d2) return false;

    return true;
}

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
#endif
    int TC;
    cin>>TC;
    REP(tc,TC){
        REP(i,3) scanf("%d %d %d %d",&b[i].first,&b[i].second,&e[i].first,&e[i].second);
        bool g=false;
        REP(i,3) REP(j,3) if(i!=j)
            if(good(i,j,3-i-j))
                g=true;
        puts(g?"YES":"NO");
    }

    return 0;
}