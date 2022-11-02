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

set<string> q;

int main(){ 
#ifdef LocalHost
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

    int total=0;
    string s;
    while(getline(cin,s)){
        if(s[0]=='-'){
            s=s.substr(1);
            q.erase(s);
        }else if(s[0]=='+'){
            s=s.substr(1);
            q.insert(s);
        }else{
            string name = "";
            REP(i,s.size()) if(s[i]==':'){
                name = s.substr(0,i);
                s=s.substr(i+1);
                break;
            }
            total += s.size() * q.size();
        }
    }
    cout<<total<<endl;
    
    return 0;
}