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

char s[1100000];
char s1[1100000];
bool pref[1100000];
bool suf[1100000];

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    gets(s);
    gets(s1);
    int n=strlen(s);
    if (n==1){
        printf("1\n1\n");
        return 0;
    }
    pref[0]=(s[0]==s1[0]);
    for (int i=1;i<n-1;i++)
        pref[i]=pref[i-1] && s[i]==s1[i];
    suf[n-1]=(s[n-1]==s1[n-2]);
    for (int i=n-2;i>0;i--)
        suf[i]=suf[i+1] && (s[i]==s1[i-1]);
    int cnt=0;
    for (int i=0;i<n;i++)
        if ((i==0 || pref[i-1]) && (i==n-1 || suf[i+1]))
            cnt++;
    printf("%d\n",cnt);
    for (int i=0;i<n;i++)
        if ((i==0 || pref[i-1]) && (i==n-1 || suf[i+1]))
            printf("%d ",i+1);
    printf("\n");   
    return 0;
}