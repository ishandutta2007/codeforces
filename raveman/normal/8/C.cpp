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

int d[1<<24];
int f[1<<24];
const int inf = 1011111111;
int dist[24];
int d2[24][24];
int x[24],y[24];

int main(){ 
#ifdef LocalHost
    freopen("input.txt","r",stdin);
#endif

    int xs,ys,n;
    cin>>xs>>ys>>n;
    REP(i,n) cin>>x[i]>>y[i],x[i]-=xs,y[i]-=ys,dist[i]=x[i]*x[i]+y[i]*y[i];
    REP(i,n)REP(j,n) d2[i][j]=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
    REP(i,1<<n) d[i]=inf;

    d[0]=0;f[0]=-1;

    FOR(i,1,1<<n){
        REP(j,n)if(i&(1<<j)){
            if(d[i] > d[i^(1<<j)] + dist[j]*2){
                d[i] = d[i^(1<<j)] + dist[j]*2;
                f[i] = i^(1<<j);
            }
            FOR(k,j+1,n) if(i&(1<<k)){
                int nmask = i ^ (1<<j) ^ (1<<k);
                if(d[i] > d[nmask] + d2[j][k]+dist[j]+dist[k]){
                    d[i]= d[nmask] + d2[j][k]+dist[j]+dist[k];
                    f[i] = nmask;                       
                }
            }

            break;
        }
    }

    int mask = (1<<n)-1;
    cout<<d[mask]<<endl;
    printf("0");
    while(mask){
        int tt = mask ^ f[mask];
        REP(i,n) if(tt&(1<<i))
            printf(" %d",i+1);
        printf(" 0");
        mask = f[mask];
    }
    puts("");
    return 0;
}