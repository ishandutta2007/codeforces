#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <memory.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <iterator>

#define mp make_pair
#define pb push_back

#ifndef LOCAL
#undef assert
#define assert(Expr) ;
#endif

using namespace std;

typedef long long int64;
typedef long double ld;

int r;
int n,m;
int dh[2][210];
int dt[2][210];
int h0,t0;

void read(){
    scanf("%d %d %d",&h0,&t0,&r);
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d %d",&dh[0][i],&dt[0][i]);
    scanf("%d",&m);
    for (int i=1;i<=m;i++)
        scanf("%d %d",&dh[1][i],&dt[1][i]);
/*  n=200;
    m=200;
    r=200;
    for (int i=1;i<=200;i++){
        dh[0][i]=rand()%201;
        dt[0][i]=rand()%201;
        dh[1][i]=rand()%201;
        dt[1][i]=rand()%201;
    }
    h0=rand()%201;
    t0=rand()%201;*/
}

int d[410][410];
int result[410][410];
int dest[410][410];
const int MAXDELT=201;
queue<pair<int,int> > q;
const string outcomes[3]={"Ivan","Zmey","Draw"};

void solve(){
    memset(d,0,sizeof(d));  
    for (int i=0;i<=MAXDELT+r+1;i++)
        for (int j=0;j<=MAXDELT+r+1;j++){           
            if (i+j==0){
                q.push(mp(i,j));
                result[i][j]=0;
                dest[i][j]=0;
                continue;
            }
            if (i+j > r){ 
                q.push(mp(i,j));
                result[i][j]=1;
                dest[i][j]=0;
                continue;
            }
            result[i][j]=2;
            d[i][j]=min(i,n)+min(j,m);              
        }
            
    for (;!q.empty();){
        int h=q.front().first;
        int t=q.front().second;                 
        q.pop();
//      if (h+t<=r) cerr<<h<<" "<<t<<" "<<result[h][t]<<endl;
        if (h==h0 && t==t0){
            cout<<outcomes[result[h][t]]<<endl;
            cout<<dest[h][t]<<endl;
            return;
        }
        for (int i=1;i<=n;i++){
            int nh=h-dh[0][i]+i;
            int nt=t-dt[0][i];                         

            if (nh<i || nt<0) continue;
            if (nh > MAXDELT+r+1 || nt>MAXDELT+r+1) continue;
            if (result[nh][nt]!=2) continue;
//            cerr<<h<<" "<<t<<" <n "<<i<<" - "<<nh<<" "<<nt<<endl;
            d[nh][nt]--;                                        
            if (result[h][t]==0 || d[nh][nt]==0){
                dest[nh][nt]=dest[h][t]+1;
                result[nh][nt]=result[h][t];
                q.push(mp(nh,nt));     
//              cerr<<"!!!!!!!"<<endl;
            }                               
        }
        for (int i=1;i<=m;i++){
            int nh=h-dh[1][i];
            int nt=t-dt[1][i]+i;
            if (nh<0 || nt<i) continue;
            if (nh > MAXDELT+r+1 || nt>MAXDELT+r+1) continue;
            if (result[nh][nt]!=2) continue;
            d[nh][nt]--;                                
//            cerr<<h<<" "<<t<<" <m "<<i<<" - "<<nh<<" "<<nt<<endl;        
            if (result[h][t]==0 || d[nh][nt]==0){
                dest[nh][nt]=dest[h][t]+1;
                result[nh][nt]=result[h][t];
                q.push(mp(nh,nt));
            }                               
        }

    }       
    cout<<outcomes[2]<<endl;    
}


int main(){
    read();
    solve();
    return 0;
}