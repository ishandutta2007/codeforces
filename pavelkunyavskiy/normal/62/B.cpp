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

const int MAXN=210000;

int add[MAXN][26];
string t;







int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int n,k;
    scanf("%d %d\n",&n,&k);
    getline(cin,t); 
    memset(add[0],-1,sizeof(add[0]));
    for (int i=0;i<MAXN;i++){
        if (i){
            for (int j=0;j<26;j++)
                if (add[i-1][j]!=-1)                    
                    add[i][j]=add[i-1][j]+1;
                else
                    add[i][j]=-1;
        }
        if (i<k){
            add[i][t[i]-'a']=0;
        }
        
        
/*      if (i<10){
            for (int j=0;j<26;j++)
                cerr<<add[i][j]<<" ";
            cerr<<endl;
        }*/
    }
    
    for (int i=k-2;i>=0;--i)
        for (int j=0;j<26;j++)
            if ((add[i][j] > add[i+1][j]+1 || add[i][j]==-1) && add[i+1][j]!=-1)
                add[i][j]=add[i+1][j]+1;
                
                
    for (int I=0;I<n;I++){
        getline(cin,t);
        int64 res=0;
        for (int i=0,sz=t.size();i<sz;i++){
            if (add[i][t[i]-'a']==-1)
                res+=sz;
            else
                res+=add[i][t[i]-'a'];
        }
        printf("%I64d\n",res);
    }   
    return 0;
}