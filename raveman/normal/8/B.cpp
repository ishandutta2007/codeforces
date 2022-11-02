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


set<pii> ss;
int main(){ 
#ifdef LocalHost
    freopen("input.txt","r",stdin);
#endif

    string s;
    cin>>s;
    int x=0,y=0;
    ss.insert(pii(x,y));
    REP(i,s.size()){
        if(s[i]=='L') x--;
        else if(s[i]=='R') x++;
        else if(s[i]=='U') y--;
        else y++;

        if(ss.count(pii(x,y))){
            puts("BUG");
            return 0;
        }
        ss.insert(pii(x,y));
    }
    for(set<pii>::iterator it = ss.begin();it!=ss.end();it++){
        int num = 0;
        FOR(dx,-1,2)FOR(dy,-1,2)if(abs(dx)+abs(dy)==1){
            int nx = it->first + dx;
            int ny = it->second +dy;
            if(ss.count(pii(nx,ny))) num++;
        }
        if(num>2 || num>1 && (*it)==pii(0,0) || num>1 && (*it)==pii(x,y)){
            puts("BUG");
            return 0;
        }
    }
    puts("OK");




    return 0;
}