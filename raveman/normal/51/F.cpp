#pragma comment(linker, "/STACK:836777216")

#include <algorithm>
#include <iostream>
#include<stdio.h>
#include<complex>
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
vi v[2222];
bool u[2222];
int par[2222];
int deep[2222];

int p[2222];
int P(int x){return p[x]==x ? x : p[x]=P(p[x]);}

int res = 0;
void join(int p1,int p2){
        if(P(p1) != P(p2)) res++;
        p[P(p2)] = P(p1);
}

vi c;
void dfs(int ver){
        if(u[ver]) return;
        u[ver]=1;
        c.pb(ver);
        REP(i,v[ver].size())
                if(!u[v[ver][i]]){
                        deep[v[ver][i]] = deep[ver] + 1;
                        par[v[ver][i]] = ver;
                        dfs(v[ver][i]);
                }
}

void go(int v1,int v2){
        while(v1!=v2){
                if(deep[v1] > deep[v2]){
                        join(v1, par[v1]);
                        v1=par[v1];
                }else{
                        join(v2, par[v2]);
                        v2=par[v2];
                }
        }
}

vi sm[2222];
int y[2222];
int f[2222];
int now;

pii parse(int ver, int par = -1){
        pii val(0,0);
        bool f = 0;
        REP(i,sm[ver].size()){
                int nw = sm[ver][i];
                if(nw==par) continue;
        
                if(y[nw]!=now){
                        f|=1;
                        pii temp = parse(nw, ver);
                        val.first += temp.first;
                        val.second &= temp.second;

                }
        }
        if(!f) return pii(0,0);
        if(val.second) val.second=0;
        else{
                val.second=1;
                if(par!=-1) val.first++;
        }
        return val;
}

int bfs(int vv,bool d=0){
        now++;
        queue<int> q;
        q.push(vv);
        y[vv]=now;

        int last;
        while(!q.empty()){
                last = q.front();q.pop();
                REP(i,sm[last].size()){
                        int ver = sm[last][i];
                        if(y[ver]!=now){
                                y[ver] = now;
                                f[ver] = last;
                                q.push(ver);
                        }
                }
        }

        int tlast = last;
        if(d){
                now ++;
                while(last!=vv){
                        y[last] = now;
                        last = f[last];
                }
                y[vv] = now;

                last = tlast;
                while(last!=vv){
                        res += parse(last).first;
                        last = f[last];
                }
                res+=parse(vv).first;

        }
        return tlast;
}

int main(){
#ifdef LocalHost    
        freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
#endif

        cin>>n>>m;

        REP(i,n) p[i]=i;
        REP(i,m){
                int x=0,y=0;
                scanf("%d %d",&x,&y);
                x--,y--;
                v[x].pb(y);
                v[y].pb(x);
        }
        REP(i,n)if(!u[i]){
                if(i) res++;
                par[i]=-1;
                c.clear();
                dfs(i);

                REP(j,c.size()){
                        int ver = c[j];
                        REP(k,v[ver].size()){
                                int nw = v[ver][k];

                                if(par[nw] != ver && par[ver]!=nw){
                                        go(nw,ver);
                                }
                        }
                }
                REP(j,c.size()){
                        int ver = c[j];
                        REP(k,v[ver].size()){
                                int nw = v[ver][k];
                                sm[P(ver)].pb(P(nw));
                                sm[P(nw)].pb(P(ver));
                        }
                }
        
                                
                REP(j,c.size()) if(P(c[j])==c[j]) UN(sm[P(c[j])]);
                int ver = P(c[0]);
                ver = bfs(ver);
                bfs(ver, 1);

        }
        cout<<res<<endl;
        return 0;
}