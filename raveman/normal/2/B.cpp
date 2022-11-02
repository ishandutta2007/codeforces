#pragma comment(linker, "/STACK:36777216")

#include <algorithm>
#include <iostream>
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

#define FOR(i,a,b) for (int i(a); i < (b); i++) 
#define REP(i,n) FOR(i,0,n) 
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back

int n;
int a[1111][1111];
int b[1111][1111];
int d[1111][1111];

const int inf = 1011111111;
int best = inf;
string res;

void go(int x,int y){
    if(x && d[x][y] == b[x][y]+d[x-1][y]){
        go(x-1,y);
        res.pb('D');
    }else if(y){
        go(x,y-1);
        res.pb('R');
    }
}

void solve(int c){
    REP(i,n)REP(j,n){
        int q=0;
        while(a[i][j] && (a[i][j]%c)==0) a[i][j]/=c,q++;
        b[i][j]=q;        
    }
    REP(i,n)REP(j,n){
        if(i) d[i][j]=b[i][j]+d[i-1][j];
        else if(j) d[i][j]=b[i][j]+d[i][j-1];
        else d[i][j]=b[i][j];

        if(i) d[i][j]=min(d[i][j],b[i][j]+d[i-1][j]);
        if(j) d[i][j]=min(d[i][j],b[i][j]+d[i][j-1]);
    }
    
    if(best>d[n-1][n-1]){
        best=d[n-1][n-1];
        res="";
        go(n-1,n-1);
    }
}

int main(){ 
#ifdef LocalHost
    freopen("input.txt","r",stdin);
#endif

    cin>>n;
    REP(i,n)REP(j,n)scanf("%d",&a[i][j]);

    solve(2),solve(5);

    REP(i,n)REP(j,n)if(a[i][j]==0 && best>1){
        best=1;
        res="";
        REP(k,i) res.pb('D');
        REP(k,j) res.pb('R');
        REP(k,n-i-1) res.pb('D');
        REP(k,n-j-1) res.pb('R');
    }

    cout<<best<<endl;
    cout<<res<<endl;

    return 0;
}