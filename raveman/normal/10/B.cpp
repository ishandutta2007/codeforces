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

int n,k,m;
bool u[111][111];
const int inf = 1011111111;

int getVal(int r,int c,int m){
    int M = m;
    int res = 0;
    if(c<k/2){
        int v2 = abs(c-(k/2));
        if(c+m-1<=k/2){
            res = m * (v2+v2-m+1)/2;
        }else{
            res = v2 * (v2+1)/2;
            m -= v2;m--;
            res += m*(m+1)/2;
        }
    }else{
        int v2 = abs(c-(k/2));
        res= m *(v2+v2+m-1)/2;
    }
    return res+ M*abs(r-(k/2));
}

int main(){    
#ifdef LocalHost
    freopen("input.txt","r",stdin);
#endif

    cin>>n>>k;
    REP(i,n){
        scanf("%d",&m);

        int x =-1,y=-1,best=inf;
        REP(row,k){
            for(int start = 0;start<k;){
                int end = start;
                while(end<k && !u[row][end]) end++;
                while(end-start>=m){
                    int v = getVal(row,start,m);
                    if(v<best) best=v,x=row+1,y=start+1;
                    start++;
                }
                start=end+1;
            }
        }

        if(best==inf) cout<<-1<<endl;
        else{
            REP(i,m) u[x-1][y-1+i]=true;
            cout<<x<<' '<<y<<' '<<y+m-1<<endl;
//cout<<best<<endl;
        }
    }

    

    return 0;
}