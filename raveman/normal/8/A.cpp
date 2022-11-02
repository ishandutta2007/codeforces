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

string s,r,s1,s2;

int fund(string &s1,string &s2,int start){
    FOR(i,start,s1.size()){
        bool g = true;
        REP(j,s2.size())
            if(s2[j]!=s1[i+j]){
                g=false;
                break;
            }
        if(g) return i;
    }
    return s1.size();
}

bool good(string &s,string &s1,string &s2){
    int pos = fund(s,s1,0);
    pos = fund(s,s2,pos+s1.size());
    return pos<s.size();
}

int main(){ 
#ifdef LocalHost
    freopen("input.txt","r",stdin);
#endif

    getline(cin,s);
    r = s;
    reverse(r.begin(),r.end());
    getline(cin,s1);
    getline(cin,s2);

    if(good(s,s1,s2) && good(r,s1,s2)) puts("both");
    else if(good(s,s1,s2)) puts("forward");
    else if(good(r,s1,s2)) puts("backward");
    else puts("fantasy");



    return 0;
}