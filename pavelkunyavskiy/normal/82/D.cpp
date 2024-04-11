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

const int MAXN=1100;

int t[MAXN][MAXN];
int a[MAXN];
int N;

const int inf=int(1e9+1e8);



int calc(int n,int last){
    int& ans = t[n][last];
    if (ans != -1)
        return ans;
    if (n == N)
        return ans = a[last];
    if (n == N-1)
        return ans = max(a[last],a[n]);
    ans = inf;
    ans = min(ans,calc(n+2,last)+max(a[n],a[n+1])); 
    ans = min(ans,calc(n+2,n)+max(a[last],a[n+1])); 
    ans = min(ans,calc(n+2,n+1)+max(a[last],a[n]));
    return ans;
}

void gen(int n,int last){
    int ans = t[n][last];
    if (n == N){
        printf("%d\n",last+1);
        return;
    }
    if (n == N-1){
        printf("%d %d\n",last+1,n+1);
        return;
    }
    if (ans == calc(n+2,last)+max(a[n],a[n+1])){
        printf("%d %d\n",n+1,n+2);
        gen(n+2,last);
        return;
    }   
    if (ans == calc(n+2,n)+max(a[last],a[n+1])){
        printf("%d %d\n",last+1,n+2);
        gen(n+2,n);
        return;
    }   
    if (ans == calc(n+2,n+1)+max(a[last],a[n])){
        printf("%d %d\n",last+1,n+1);
        gen(n+2,n+1);
        return;
    }
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    memset(t,-1,sizeof(t));
    scanf("%d",&N);
    int n=N;
    for (int i=0;i<n;i++)
        scanf("%d",&a[i]);
    int tmp = calc(1,0);
    cout<<tmp<<endl;
    gen(1,0);
    return 0;
}