#pragma comment(linker, "/STACK:36777216")

#include <algorithm>
#include <iostream>
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

#define FOR(i,a,b) for (int i(a); i < (b); i++) 
#define REP(i,n) FOR(i,0,n) 
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back

#define SORT(a) sort((a).begin(),(a).end())

char s[111111];
int p[111111],c[111111];
int a[111111],b[111111];
vector<pii> v;
int n;
int ff;

int sum;
bool good(){
    int c = 0;
    REP(i,n){
        if(s[i]==')'){
            c--;
            if(c<0) return false;
        }
        else c++;
    }
    sum=c;
    return c <= 2*ff;
}

struct P{
    int beg,end;
    int add,mn;
    int left,right;
    P(){mn=0;add=0;left=right=-1;}
    int getMin(){
        return mn;
    }
    void addd(int val,int from){
        if(from<=beg){
            add+=val;
            mn+=val;
        }else if(end<from){
            return;
        }else{
            t[left].addd(add,0);
            t[right].addd(add,0);
            
            t[left].addd(val,from);
            t[right].addd(val,from);
            add=0;

            mn = min(t[left].mn,t[right].mn);
        }
    }
} t[222222];

int curr;

void buildT(int left,int right){
    t[curr].beg=left;
    t[curr].end=right;
    if(left<right){
        int temp = curr;
        curr++;
        
        t[temp].left=curr;
        buildT(left,(left+right)/2);

        curr++;
        t[temp].right=curr;
        buildT((left+right)/2+1,right);
    }
}

int main(){ 
#ifdef LocalHost
    freopen("input.txt","r",stdin);
#endif

    gets(s);
    ll total = 0;
    n = strlen(s);
    buildT(0,n-1);
    int c = 0;
    REP(i,n) if(s[i]=='?') p[c]=i,c++;
    REP(i,c) scanf("%d %d",&a[i],&b[i]),v.pb(pii(b[i]-a[i],i)),total+=a[i];
    SORT(v);

    ff = c;
    if(!good()){
        puts("-1");
        return 0;
    }
    REP(i,n)
        if(s[i]==')')
            t[0].addd(-1,i);
        else t[0].addd(1,i);

    REP(i,c){
        s[p[v[i].second]]=')';
        sum-=2;

        t[0].addd(-2,p[v[i].second]);
        ff--;
        if(t[0].getMin()>=0 && sum<=2*ff) total+=v[i].first;        
        else{
            sum+=2;
            s[p[v[i].second]]='(';
            t[0].addd(2,p[v[i].second]);
        }
    }
    if(sum) puts("-1");
    else {
        cout<<total<<endl;
        cout<<s<<endl;
    }

    return 0;
}