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

int n;
int a[111111];
map<int,vi> m;
vi s[111111];

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

    cin>>n;
    REP(i,n) scanf("%d",a+i),m[a[i]].pb(i);

    int start = 0;
    for(map<int,vi>::iterator it = m.begin();it!=m.end();it++){
        vi &v = it->second;
        REP(i,v.size()) REP(j,i)
            s[v[i] - v[j]].pb(v[j]);
    }
    FOR(i,1,n) if(a[i-1]==a[i]) start = i;

    for(int i=2;i<=n/2;i++)if(s[i].size()){
        SORT(s[i]);
        vi &t = s[i];
        bool p = true;
        int pos = 1;
        int num = 0;
        while(pos<t.size() && t[pos]<start) pos++;
        while(pos<t.size()){
            if(t[pos] == t[pos-1] + 1) num ++;
            else num = 0;
            if(num+1 == i){
                start = t[pos] + 1;
                pos+=2;
                num=0;
                continue;
            }
            pos++;
        }
    }

    cout<< n - start<<endl;
    FOR(i,start,n){
        if(i!=start) printf(" ");
        printf("%d",a[i]);
    }
    puts("");

    return 0;
}