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

string a[3];
string res[6];
char tmp[700];
char tmp2[700];

string get(){
    gets(tmp);
    int cnt=0;
    for (int i=0;tmp[i];++i)
        if ('a'<=tmp[i] && tmp[i]<='z')
            tmp2[cnt++]=tmp[i];
        else if ('A'<=tmp[i] && tmp[i]<='Z')
            tmp2[cnt++]=tmp[i]-'A'+'a';
    tmp2[cnt++]=0;
    return string(tmp2);
}

void solve(){
    string ans=get();
    for (int i=0;i<6;i++)
        if (ans == res[i]){
            printf("ACC\n");
            return;
        }
    printf("WA\n");
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    a[0]=get();
    a[1]=get();
    a[2]=get();
    sort(a,a+3);
    for (int i=0;i<6;i++){
        res[i]=a[0]+a[1]+a[2];
        next_permutation(a,a+3);        
    }
    gets(tmp);
    int n;
    sscanf(tmp,"%d",&n);
    for (int i=0;i<n;i++)
        solve();
    return 0;
}