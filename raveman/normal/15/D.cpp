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

int n,m;
int a,b;
int d[1111][1111];
int c[1111][1111];
int e[1111][1111];
ll s[1111][1111];

map<int,int> q;

pair<ll,int> v[1000111];
bool u[1111][1111];
vector<pair<ll,int> > rs;

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
#endif

    cin>>n>>m>>a>>b;
    REP(i,n)REP(j,m){
        scanf("%d",&d[i][j]);
        s[i][j] = (i?s[i-1][j]:0) +(j?s[i][j-1]:0) +(i&&j?-s[i-1][j-1]:0) + d[i][j];
    }
    
    REP(i,n){
        q.clear();
        REP(j,b) q[d[i][j]]++;
        REP(j,m-b+1){
            c[i][j] = q.begin()->first;

            q[d[i][j]] --;
            if(q[d[i][j]]==0)
                q.erase(d[i][j]);
            q[d[i][j+b]]++;
        }
    }

    REP(j,m-b+1){
        q.clear();
        REP(i,a) q[c[i][j]]++;
        REP(i,n-a+1){
            e[i][j] = q.begin()->first;

            q[c[i][j]]--;
            if(q[c[i][j]]==0)
                q.erase(c[i][j]);
            q[c[i+a][j]]++;
        }
    } 
    int pos = 0;
    REP(i,n-a+1) REP(j,m-b+1){
        ll sum = s[i+a-1][j+b-1] - (i?s[i-1][j+b-1]:0) - (j?s[i+a-1][j-1]:0) + (i&&j?s[i-1][j-1]:0) - ll(e[i][j]) * a * b;

        v[pos] = pair<ll,int>(sum, i*1111+j);
        pos++;
    }
    sort(v,v+pos);
    REP(i,pos){
        int x = v[i].second/1111;
        int y = v[i].second%1111;
        if(!u[x][y]){
            rs.pb(v[i]);
            FOR(dx,-a+1,a)FOR(dy,-b+1,b)if(x+dx>=0 && x+dx<n && y+dy>=0 && y+dy<m)
                u[x+dx][y+dy]=true;
        }
    }

    cout<<rs.size()<<endl;
    REP(i,rs.size()){
        int x = rs[i].second/1111;
        int y = rs[i].second%1111;
        printf("%d %d %lld\n",x+1,y+1,rs[i].first);
    }
    return 0;
}