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

vi res;
int pos;
string s;

void go(int w = -1){
        while(pos+7<s.size() && s.substr(pos,7) == "<table>"){
                res.pb(0);
                pos+=7;
                go(res.size()-1);
                pos+=8;
        }
        while(pos+4<s.size() && s.substr(pos,4) == "<tr>"){
                pos+=4;
                go(w);
                pos+=5;
        }
        while(pos+4<s.size() && s.substr(pos,4) == "<td>"){
                pos+=4;
                go(w);
                pos+=5;
                res[w]++;
        }
}

int main(){
#ifdef LocalHost    
        freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
#endif
        string t;
        while(cin>>t) s+=t;

        go();
		SORT(res);
        REP(i,res.size()){
                if(i)printf(" ");
                printf("%d",res[i]);
        }
        puts("");
        return 0;
}