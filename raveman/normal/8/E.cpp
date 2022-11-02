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

int n;
ll k;
bool u[55];
int len;
int len_down;

int getNum(){
    int total = 0;
    int mask = 0;
    REP(i,len_down)  mask<<=1,mask|=u[i];
    
    total += (1<<(len_down-1)) - (((mask)));
    total += (1<<(len_down-1)) - (((mask)));
    //total += (mask>>1)+1;

    if(len!=len_down && u[len_down]) total--;


    return total;
}

bool v[55];
void stupid(int n,int k){
    while(1){
        bool good = true;

        REP(i,n)
            if(v[i]!=v[n-i-1]){
                if(v[i]) good=false;
                break;
            }
        REP(i,n)
            if(v[i]==v[n-i-1]){
                if(v[i]) good=false;
                break;
            }

        
        if(good){
            k--;
            if(k==0){
                REP(i,n) cout<<(v[i]?1:0);
                puts("");
                return;
            }
        }

        int pos = n-1;
        while(pos>=0 && v[pos]) v[pos]=0,pos--;
        if(pos==0) break;
        v[pos]=true;
    }
    puts("-1");
}

int main(){ 
#ifdef LocalHost
    freopen("input.txt","r",stdin);
#endif

    cin>>n>>k;
    //stupid(n,k+1);
    k++;
    len = (n+1)/2;
    len_down = n/2;

    while(1){

        int num = getNum();

        if(k<=num){
            while(1){
                
                bool good = true;
                if(u[n-1]){
                    REP(i,len) if(u[i]!=u[n-i-1]) continue;
                    else if(u[i]) {good=false;break;}
                    else break;
                }else{
                    REP(i,len) if(u[i]==u[n-i-1]) continue;
                    else if(u[i]) {good=false;break;}
                    else break;

                }


                if(good){
                    k--;
                    if(k==0) break;
                }
                int p = n-1;
                while(u[p]) u[p]=0,p--;
                if(p<=len-1) puts("FUCK");
                u[p]=true;

            }
            REP(i,n) cout<<(u[i]?1:0);
            
            puts("");
            return 0;
        }else k-=num;

        int pos = len - 1;
        while(u[pos]) u[pos]=false,pos--;
        if(pos==0) break;
        u[pos]=true;
    }
    puts("-1");

    return 0;
}