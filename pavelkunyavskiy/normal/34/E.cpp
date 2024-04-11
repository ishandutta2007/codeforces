#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <iterator>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>
#define mp make_pair
#define pb push_back                     
#define setval(a,v) memset(a,v,sizeof(a))

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

typedef long long int64;
typedef long double ld;

ld eps=1e-09;

ld x[100];
ld v[100];
ld m[100];
int n;
ld curt,t;

ld findnext(){
    ld ans=t-curt;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            if (i!=j)
                if (x[i]<x[j]-eps && (v[j]-v[i]<-eps))
                    ans=min(ans,(x[i]-x[j])/(v[j]-v[i]));
   return ans;
}

void make(ld time){
   // cerr<<time<<endl;
    curt+=time;
    for (int i=0;i<n;i++)
        x[i]+=v[i]*time;
}

void stolk(){
    for (int i=0;i<n;i++)
        for (int j=i+1;j<n;j++)
           if (abs(x[i]-x[j])<eps){
                   ld v1=v[i];
                   ld v2=v[j];
                   v[i]=((m[i]-m[j])*v1+2*m[j]*v2)/(m[i]+m[j]);
                   v[j]=((m[j]-m[i])*v2+2*m[i]*v1)/(m[i]+m[j]);
               }

}
      
    
int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    cin>>n>>t;
    curt=0;
    for (int i=0;i<n;i++)
        cin>>x[i]>>v[i]>>m[i];
    for (;t-curt>eps;){
       make(findnext());
       stolk(); 
    }               
    for (int i=0;i<n;i++){
        cout.precision(7);
        cout<<fixed<<x[i]<<endl;;
    }
    cout<<endl;
    return 0;
}