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

int n;
int m[11];
int a[11][1111];

int next[11][1111][256];
int nx[256];

const int inf = 1011111111;

set<ll> s[257][256];
vi bb[257][256];
int sm[257][256];
int res;vi vv;
vi cc;

bool better(const vi &v1,vi &v2){
    REP(i,n)if(v2[i]<v1[i]) return true;
    return false;
}
ll hash(vi &v){
    ll r =0;
    REP(i,n) r=r*10007+v[i];
    return r;
}
void go(vi &v,int last,int pos,int from=-1){
	if(clock()>0.9*CLOCKS_PER_SEC) return;
    if(pos>res){
        res=pos;
        vv=cc;
    }
    

    if(last!=-1){
        ll x = hash(v);
        if(s[pos][last].count(x)) return;
            s[pos][last].insert(x);//[v] = from;

        if(sm[pos][last]!=-1){
            bool good=false;
            REP(i,n)if(v[i]<bb[pos][last][i]) {good=true;break;}
            if(!good) return;
        }
        int sum=0;REP(i,n) sum+=v[i];
        if(sm[pos][last]>sum){
            sm[pos][last]=sum;
            bb[pos][last]=v;
        }
        

    }
    for(int nx = last+1;nx<=255;nx++){
        vi t=v;
        bool good=true;
        REP(j,n) t[j]=next[j][t[j]][nx],good&=(t[j]!=inf);
        if(good){
            cc.pb(nx);
            go(t,nx,pos+1,last);
            cc.pop_back();
        }
    }
    
}

int main(){    
#ifdef LocalHost
    freopen("input.txt","r",stdin);
#endif
CL(sm,-1);
    cin>>n;
    REP(i,n){
        cin>>m[i];
        REP(j,m[i]) scanf("%d",&a[i][j+1]);
        a[i][0]=-1;
    }
    REP(i,n){
        REP(j,256) nx[j]=inf;
        for(int j=m[i];j>=0;j--){
            if(j)nx[a[i][j]]=j;
            memcpy(next[i][j],nx,sizeof nx);
        }
    }
    vi v(n,0);
    go(v,-1,0);

    cout<<res<<endl;
    if(res){

        vi r=vv;
        REP(i,r.size()){
            if(i) printf(" ");
            cout<<r[i];
        }
        puts("");
    }
    return 0;
}