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

char s[255][255];
int  u[255][255];
int now;
int n,m,cc;

void dfs(int x,int y){
    if(u[x][y]==now) return;
    u[x][y]=now;
    cc++;
    FOR(dx,-1,2)FOR(dy,-1,2){
        int nx = x +dx;
        int ny = y+dy;
        if(nx>=0 && nx<n && ny>=0 && ny<m && s[nx][ny]=='1')
            dfs(nx,ny);
    }        
}
int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif


    int TC;
    cin>>TC;
    REP(tc,TC){
        cin>>n>>m;
        gets(s[0]);
        REP(i,n) gets(s[i]);

        int res = 0;
        now++;  
        REP(i,n)REP(j,m)if(u[i][j]!=now && s[i][j]=='1'){
            bool good = false;

            int len = 0;
            while(j+len<m && s[i][j+len]=='1') len++;

            if(len>1 && i+len<=n){
                good = true;
                REP(z,len) if(s[i][j+z]!='1') good=false;
                REP(z,len) if(s[i+z][j]!='1') good=false;
                REP(z,len) if(s[i+z][j+len-1]!='1') good=false;
                REP(z,len) if(s[i+len-1][j+z]!='1') good=false;                
            }

            if(!good){
                len=0;
                while(j+len<m && i+len<n && s[i+len][j+len]=='1') len++;
                if(len>1 && j-len+1>=0 && i+len-1+len-1<n){
                    good = true;
                    REP(z,len) if(s[i+z][j+z]!='1') good=false;
                    REP(z,len) if(s[i+z][j-z]!='1') good=false;
                    REP(z,len) if(s[i+len-1+z][j-len+1+z]!='1') good=false;
                    REP(z,len) if(s[i+len-1+z][j+len-1-z]!='1') good=false;                
                }
            }

            cc=0;
            dfs(i,j);
            if(good){
                if(cc==len*4 - 4)
                    res++;
            }
        }
        cout<<res<<endl;
    }
    
    return 0;
}