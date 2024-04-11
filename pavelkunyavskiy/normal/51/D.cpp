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

int a[110000];

int gcd(int a,int b){
  #ifndef ONLINE_JUDGE
    assert(a>=0 && b>=0);
  #endif
    if (!a || !b) return a+b;
    return gcd(b,a%b);
}

int gcds(int a,int b){
    return gcd(abs(a),abs(b));
}
const int BAD=int(1e+9);
int n;

int check(int Ex){
    int start,qch,qzn,cur;
    int can;
    if (Ex==0){
        start=3;
        qch=a[2];
        qzn=a[1];
        cur=a[2];
        if (a[1]==0 && a[2]!=0) return 2;       
        can=1;
    }
    else if (Ex==1){
        start=3;
        qch=a[2];
        qzn=a[0];
        cur=a[2];
        if (a[0]==0 && a[2]!=0) return 2;
        can=1;
    }       
    else {
        start=2;
        qch=a[1];
        qzn=a[0];
        cur=a[1];
        if (a[0]==0 && a[1]!=0) return 2;
        can=0;
    }   
    int g=gcds(qch,qzn);
    if (g!=0){
        if (qch<0){
            qch*=-1;qzn*=-1;
        }
        qch/=g; 
        if (qzn<0){ 
            qzn*=-1;qch*=-1;
        }
        qzn/=g;
    }
    else
        qch=qzn=0;
    
    if (qzn==0){
        for (int i=start;i<n;i++){
            if (a[i]!=0)
                can++;          
        }
        return min(2,can);
    }
    for (int i=start;i<n;i++){
        if (cur==BAD || abs(cur)%qzn!=0)
            cur=BAD;
        else {
            cur=cur/qzn*qch;
        }
        while (i<n && a[i]!=cur)    can++,i++;      
    }
    return min(2,can);
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%d",&a[i]);
    int ans=check(0);
    ans=min(ans,check(1));
    ans=min(ans,check(2));
    cout<<ans<<endl;
    return 0;
}