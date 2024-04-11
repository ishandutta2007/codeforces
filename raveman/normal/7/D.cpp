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

string s;
int p[5111111];

void buildP(){
    int curr = -1;
    p[0]=curr;
    FOR(i,1,s.size()){
        while(curr>=0 && s[i]!=s[curr+1]) curr=p[curr];
        if(s[i]==s[curr+1]) curr++;
        p[i]=curr;
    }
}

bool c[5111111];

void check(){
    REP(i,s.size()){
        bool pal = 1;
        int p1 =0 ,p2 = i;
        while(p1<p2) pal&=(s[p1]==s[p2]),p1++,p2--;
        while(pal!=c[i+1])
            puts("FUCK");
    }
}

int main(){    
#ifdef LocalHost
    freopen("input.txt","r",stdin);
#endif

    getline(cin,s);
    int n = s.size();
    buildP();    

    int curr=-1;
    REP(i,n){
        while(curr>=0 && s[n-1-i]!=s[curr+1]) curr=p[curr];
        if(s[n-1-i]==s[curr+1]) curr++;

        while(curr + 1 > n - 1 - i) 
            curr=p[curr];

        
        if(n-i-1 == curr+2){
    //        cout<<"Found with len "<<2*(curr+1)+1<<endl;
            c[2*(curr+1)+1]=true;
        }

        if(curr+1 == n-1-i){
  //          cout<<"Found with len "<<2*(curr+1)<<endl;
            c[2*(curr+1)]=true;
            if(curr>=0 && curr == p[curr]+1){
//                cout<<"Found with len "<<2*(curr+1)-1<<endl;
                c[2*(curr+1)-1]=true;
            }
            curr=p[curr];
        }
    }
    //cout<<"Found with len 1"<<endl;
    c[1]=true;

    ll r =0 ;
    REP(i,n){
        p[i]=0;
        if(c[i+1]) p[i]=p[(i+1)/2-1]+1;
        r+=p[i];
    }
    cout<<r<<endl;

    return 0;
}