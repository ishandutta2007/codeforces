#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
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

int64 kol[10];
int64 L,R;

string inttostr(int64 x){
    string res="";
    for (;x;x/=10)
        res=char(x%10+'0')+res;
    return res; 
}

int64 st10(int x){
    int64 res=1;
    for (;x;--x)
        res*=10;
    return res;
}


int64 gen(){
    string l=inttostr(L);
    string r=inttostr(R);
    int64 ans=0;
    
    if (l.size() == r.size()){
    //  cerr<<l<<" "<<r<<endl;
        if (l[0]!='1')
            return 0;
        if (r[0] != '1')
            return st10(l.size()-1)*2-L;
        return R-L+1;
    }
    
    for (int i=1;;i++){
        if (i<l.size())
            continue;
        if (i>r.size())
            break;
        if (i==l.size()){
            int64 tmp=st10(l.size()-1);
            tmp=2*tmp-1;
            if (tmp < L) continue;
                ans+=tmp-L+1;
            continue;
        }
        if (i==r.size()){
            int64 tmp=st10(r.size()-1);
            int64 tmp2=tmp*2-1;
            ans+=min(tmp2,R)-tmp+1;
            continue;   
        }           
        ans+=st10(i-1);
    }
    return ans;
}

ld prob[1100];
ld prob1[1100];
int64 L1[1100];
int64 R1[1100];



int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int n,k;
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>L1[i]>>R1[i];
    cin>>k;
    for (int i=0;i<n;i++)
        prob[i]=prob1[i]=0;
    prob[0]=1;
    for (int i=0;i<n;i++){
        L=L1[i];
        R=R1[i];
        ld p=(ld)gen()/(ld)(R-L+1);
        for (int j=0;j<=n;j++){
            prob1[j]+=prob[j]*(1-p);
            prob1[j+1]+=prob[j]*p;
        }
        for (int j=0;j<=n;j++){
            prob[j]=prob1[j];
            prob1[j]=0;
        }
    }
    

    ld ans=0;
    for (int i=0;i<=n;i++)
        if (i*100 >= n*k)
            ans+=prob[i];
    cout.precision(15);
    cout<<fixed<<ans<<endl;
    return 0;
}