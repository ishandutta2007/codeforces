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

int d[100][100];

char s[110000];
char s1[110000];
char s2[110000];
      
    
int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    for (int i=0;i<26;i++){
        for (int j=0;j<26;j++)
            d[i][j]=1<<29;
        d[i][i]=0;
    }
    gets(s);
    gets(s1);
    int m;
    scanf("%d",&m);
    for (int i=0;i<m;i++)
        {
            char c1,c2;int w;
            scanf(" %c %c %d",&c1,&c2,&w);
            d[c1-'a'][c2-'a']=min(d[c1-'a'][c2-'a'],w);
        }
    for (int k=0;k<26;k++)
        for (int i=0;i<26;i++)
            for (int j=0;j<26;j++)
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    int n=strlen(s);
    if (strlen(s1)!=n){
        printf("-1\n");
        return 0;
    }
    int64 ans=0;
    for (int i=0;i<n;i++){
        int tmp=1000000;
        for (int j=0;j<26;j++){
            if (d[s[i]-'a'][j]+d[s1[i]-'a'][j] < tmp){
                tmp=d[s[i]-'a'][j]+d[s1[i]-'a'][j];
                s2[i]=j+'a';
            }               
        }
//        cerr<<i<<" "<<tmp<<endl;
        if (tmp==1000000){
            printf("-1\n");
            return 0;
        }
        ans+=tmp;
    }
    s2[n]=0;
    cout<<ans<<endl;
    puts(s2);
    return 0;
}