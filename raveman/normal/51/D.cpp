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

int n;
int a[111111];
vi v;

bool good(vi &v, int c, int z = 1){
        FOR(i,1,v.size()) if(v[i]*z!=v[i-1]*c) return 0;
        return 1;
}

bool g(vi &v){
        return (v.size()<=1 || good(v, 0) || good(v, 1) || good(v, -1) || v[1] && v[0] && good(v, v[1], v[0]));
}

bool tr(vi &v,int c){
        int pos = 1;
        bool f = 0;
        int now = v[0];
        FOR(i,1,v.size()){
                now *= c;

                while(i<v.size() && v[i]!=now){
                        if(f) return 0;
                        f=1;
                        i++;
                }
        }
        return 1;
}

bool can(vi &v){
        return tr(v,1) || tr(v,-1) || tr(v,0);
}

int main(){
#ifdef LocalHost    
        freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
#endif

        cin>>n;
        v.resize(n);
        REP(i,n) scanf("%d",a+i),v[i]=a[i];

        if(g(v)){
                puts("0");
                return 0;
        }
        
        if(v.size()<50){
                REP(i,v.size()){
                        vi t = v;
                        t.erase(t.begin() + i);
                        if(g(t)){
                                puts("1");
                                return 0;
                        }
                }
                puts("2");
                return 0;
        }

        vi tt = v;
        tt.erase(tt.begin());
        if(can(v) || g(tt)){
                puts("1");
                return 0;
        }
        puts("2");
        return 0;
}