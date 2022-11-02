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

int q[1111];
vector<pii> v[1111];

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif
  
    int n;
    cin>>n;
    REP(i,n) scanf("%d",q+i);
    int m;
    cin>>m;
    REP(i,m){
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        x--,y--;
        v[y].pb(pii(z,x));
    }
    int sum = 0;
    int num =0 ;
    REP(i,n){
        SORT(v[i]);
        if(v[i].size()) sum += v[i][0].first;
        else num++;
    }
    if(num==1) cout<<sum<<endl;
    else cout<<-1<<endl;
   
    return 0;
}