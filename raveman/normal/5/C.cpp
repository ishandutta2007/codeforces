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

char s[1111111];
int  a[1111111];
int  e[1111111];
int  p[2222222];

const int add = 1111111;
int mx=0,num=1;


int mn[2222222];
int getM(int p1,int p2){
    p1+=add,p2+=add;
    int res = 1011111111;
    while(p1<=p2){
        res=min(res,mn[p1]);
        res=min(res,mn[p2]);
        p1=(p1+1)/2;
        p2=(p2-1)/2;
    }
    return res;
}
void addM(int pos,int val){
    pos+=add;
    while(pos){
        mn[pos]=min(mn[pos],val);
        pos>>=1;
    }
}

int main(){ 
#ifdef LocalHost
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif
    REP(i,2222222) mn[i]=1011111111;

    CL(e,-1);
    gets(s);
    int n = strlen(s);
    REP(i,n) a[i+1]=a[i]+(s[i]=='('?1:-1);
    e[0]=0;
    CL(p,-1);
    p[0+add]=0;    
    FOR(j,1,n+1){
        int len = 0;

        if(p[add+a[j]]!=-1){
            len = j - p[add+a[j]];
            len += e[p[add+a[j]]];

            int vl = getM(p[add+a[j]],j);
            if(vl<a[j]){
                len=0;
            }

            if(mx<len) mx=len,num=0;
            if(mx==len) num++;
        }

        p[add+a[j]]=j;
        e[j]=len;
        addM(j,a[j]);
    }

    if(mx==0) num=1;
    cout<<mx<<' '<<num<<endl;
    
    return 0;
}