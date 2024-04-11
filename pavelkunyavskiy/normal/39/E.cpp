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
#define forn(i,n) for(int i=0;i<(n);++i)
#define ford(i,n) for(int i=(n)-1;i>=0;--i)

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

typedef long long int64;
typedef long long ll;
typedef long double ld;

struct sost{
    int a,b;
    sost(){};
    sost(int A,int B){
        a=A;
        b=B;
    }
};

bool operator<(const sost& a,const sost& b){
    return a.a<b.a || (a.a==b.a && a.b<b.b);
}

map<sost,int> t;

int n;

int pow(int a,int b){
    if (!b) return 1;
    if (b&1){
        int64 tmp=pow(a,b-1)*1LL*a;
        if (tmp>=n)
            return n+100;
        return tmp;
    }
    int64 tmp=pow(a,b>>1);
    if (tmp>=n || tmp*tmp>=n)
        return n+100;
    return tmp*tmp;     
}

int calc(const sost& a){
    int kol=pow(a.a,a.b);
    if (kol>=n)
        return 2;
    if (a.a==1 && pow(2,a.b)>=n)
        return 1;
    if (a.b==1 && pow(a.a,2)>=n){
        if (((n^(a.a))&1)==1)
            return 0;
        return 2;
    }
    if (t.find(a)!=t.end())
        return t[a];
    int ans=0;
    ans=max(ans,2-calc(sost(a.a+1,a.b)));
    ans=max(ans,2-calc(sost(a.a,a.b+1)));
    t[a]=ans;
    return ans;
}



int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int a,b;
    scanf("%d %d %d",&a,&b,&n);
    int ans=calc(sost(a,b));
    if (ans==0){
        printf("Stas\n");
        return 0;
    }
    if (ans==1){
        printf("Missing\n");
        return 0;
    }
    printf("Masha\n");          
    return 0;
}