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

int cnt[MAXN];
string s;

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int n;
    scanf("%d",&n);
    cin>>s;
    cnt[0]=1;
    for (int i=1;i<=n;i++){
        if (s[i-1] == '=')
            cnt[i]=cnt[i-1];
        else if (s[i-1] == 'R')
            cnt[i]=cnt[i-1]+1;          
        else {
            cnt[i]=1;
            for (int j=i;j>0;--j){
                if (s[j-1]=='L' && cnt[j] == cnt[j-1])
                    cnt[j-1]++;
                if (s[j-1]=='=' && cnt[j] != cnt[j-1])
                    cnt[j-1]++;
            }
        }
    }
    for (int i=0;i<n;i++)
        cout<<cnt[i]<<" ";
    cout<<endl;
    return 0;
}