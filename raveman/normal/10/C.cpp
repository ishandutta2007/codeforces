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

int n;

ll a[10];
int f[1111111];

int main(){    
#ifdef LocalHost
    freopen("input.txt","r",stdin);
#endif

    cin>>n;
    FOR(i,1,n+1) a[i%9]++;

    ll res =0 ;
    REP(i,10) REP(j,10){
        res+=a[i]*a[j]*a[(i*j)%9];
    }
    FOR(i,1,n+1){
        for(int j=2;j*j<=i;j++){
            if(i%j==0){
                int c =0;
                int t =i;
                while(t%j==0) t/=j,c++;
                f[i] = f[t] * (c+1);
                break;
            }
        }
        if(!f[i]){if(i==1) f[i]=1;
        else f[i]=2;
        }
        //cout<<f[i]<<' '<<i<<endl;
        //if(i>1) res--;
        res-=f[i];        
    }
    cout<<res<<endl;

    return 0;
}