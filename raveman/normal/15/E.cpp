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

const int mod = 1000000009;

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
#endif

    int n;
    cin>>n;

    ll res = 2;

    ll curr = 1;
    ll sum = 1;
    ll prev = 1;
    for(int i = 4;i<=n;i+=2){
        res += (sum*4);
        res%=mod;


        prev += (curr*4); prev%=mod;
        curr = (curr*2); curr%=mod;
        sum*=prev;  sum%=mod;
    }

    cout<<(2*res*res+2)%mod<<endl;
    return 0;
}