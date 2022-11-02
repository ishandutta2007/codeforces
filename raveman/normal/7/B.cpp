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

int nb(int mask){return mask==0?0:1+nb(mask&(mask-1));}


map<int,pii> m;
int n,t,len,id;
bool u[111];
string s;
int qq;

int num(int pos){
    int rr = pos;
    while(rr<=n && !u[rr]) rr++;
    return rr-pos;
}

int main(){ 
#ifdef LocalHost
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

    cin>>t>>n;
    REP(i,t){
        cin>>s;
        if(s=="alloc"){
            cin>>len;

            int f = -1;
            FOR(j,1,n+1){
                if(num(j)>=len){
                    f=j;
                    REP(q,len)u[j+q]=true;
                    break;
                }
            }
            if(f==-1) puts("NULL");
            else{
                qq++;
                cout<<qq<<endl;
                m[qq]=pii(f,len);
            }

        }else if(s=="erase"){
            cin>>id;
            if(!m.count(id)) puts("ILLEGAL_ERASE_ARGUMENT");
            else{
                pii v = m[id];
                m.erase(id);
                REP(i,v.second)
                    u[v.first+i]=false;
            }
        }else{
            vector<p3i> v;
            for(map<int,pii>::iterator it = m.begin();it!=m.end();it++){
                v.pb(p3i(it->second.first,pii(it->first,it->second.second)));
            }
            m.clear();
            CL(u,false);
            SORT(v);
            int start = 1;
            REP(j,v.size()){
                p3i curr = v[j];
                m[curr.second.first] = pii(start, curr.second.second);
                start += curr.second.second;
            }
            FOR(j,1,start) u[j]=true;
            start=start;
            start=start;
        }
    }

    return 0;
}