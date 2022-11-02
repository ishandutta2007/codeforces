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

pair<string,string> split(string s){
    string s1,s2;
    REP(i,s.size())if(s[i]=='-'){
        s1=s.substr(0,i);
        s2=s.substr(i+1);
        break;
    }
    return pair<string,string>(s1,s2);
}

pii split2(string s){
    REP(i,s.size()) if(!isdigit(s[i])) s[i]=' ';
    stringstream ss(s);
    int a,b;
    ss>>a>>b;
    return pii(a,b);
}

string s[111],s1,s2;
map<string,int> sc,diff,scor;


int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

    int n;
    cin>>n;
    REP(i,n) cin>>s[i],sc[s[i]]=0;
    REP(i,n*(n-1)/2){
        cin>>s1>>s2;
        pair<string,string> ss = split(s1);
        pii score = split2(s2);
        if(score.first>score.second) sc[ss.first]+=3;
        else if(score.first==score.second) sc[ss.first]+=1;
        else sc[ss.first]+=0;

        if(score.first<score.second) sc[ss.second]+=3;
        else if(score.first==score.second) sc[ss.second]+=1;
        else sc[ss.second]+=0;

        diff[ss.first] += score.first - score.second;
        diff[ss.second] += score.second - score.first;

        scor[ss.first] += score.first;
        scor[ss.second] += score.second;
    }
    vector<pair<pii,pair<int,string> > > v;
    for(map<string,int>::iterator it = sc.begin();it!=sc.end();it++){
        string name = it->first;
        v.pb(make_pair(pii(-sc[name],-diff[name]),pair<int,string>(-scor[name],name)));
    }
    SORT(v);
    vector<string> q;
    REP(i,v.size()/2) q.pb(v[i].second.second);
    SORT(q);
    REP(i,q.size()) cout<<q[i]<<endl;

    return 0;
}