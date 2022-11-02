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

const int mod = 51123987;

char s[2222222];
int n;
int l[4444444];
int a[2222222];
int m[2222222];

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

    scanf(" %d %s",&n,s);
    CL(l,-1);
    for(int i = 0; i < 2*n + 1;){
        l[i] = max(l[i],i&1?1:0);

        while((i-1)/2 - (l[i]+1)/2>=0 && i/2 + (l[i]+1)/2 && s[(i-1)/2 - (l[i]+1)/2]==s[i/2 + (l[i]+1)/2]) l[i]+=2;

        int j = i+1;

        while(i-(j-i)>=0){
            l[j] = l[i-(j-i)];
            if((j-1)/2 + l[j]/2 >= (i-1)/2 +l[i]/2){
                l[j] -= 2*((j-1)/2 + l[j]/2 - ((i-1)/2 +l[i]/2));
                break;
            }
            j++;
        }

        i=j;
    }
    REP(i,2*n+1)if(l[i]){
        a[ i/2 - l[i]/2 ] ++;
        a[ (i-1)/2 + 1]--;

        m[ i/2 ]++;
        m[ (i-1)/2 + l[i]/2 + 1] --;

    }
    ll res =0;
    ll now = 0;
    ll end = 0;
    ll sum = 0;
    REP(i,n+1){
        now += a[i];


        res = (res + ((now-1)*now/2))%mod;
        res = (res + (now%mod) * (sum%mod))%mod;

        sum += now;
        end += m[i];
        sum -= end;
    }
    cout<<res<<endl;
    return 0;
}