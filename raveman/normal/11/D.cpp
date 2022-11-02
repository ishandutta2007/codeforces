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

int n,m;
bool a[22][22];
ll d[1<<19][19];

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

    cin>>n>>m;
    REP(i,m){
        int x,y;
        scanf("%d %d",&x,&y);
        x--,y--;
        a[x][y]=a[y][x]=1;
    }
    REP(i,n) d[1<<i][i]=1;
    ll res = 0;
    FOR(mask,1,1<<n){
        int first = -1;
        REP(i,n)if(mask&(1<<i)){
            if(first==-1) first = i;
            FOR(j,first+1,n) if(a[i][j] && !(mask&(1<<j)))
                d[mask|(1<<j)][j] += d[mask][i];
            if(a[i][first])
                res+=d[mask][i];
        }
    }
    cout<<(res-m)/2<<endl;
    return 0;
}