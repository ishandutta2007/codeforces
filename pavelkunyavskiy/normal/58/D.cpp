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

int maxsize;
int sumlen;
vector<string> s[15];
char tmp[100];
int n;

bool cmp(const string& a,const string& b){
    int tmp=min(a.size(),b.size());
    for (int i=0;i<tmp;i++)
        if (a[i]!=b[i])
            return a[i]<b[i];
    return false;
}


int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    gets(tmp);
    sscanf(tmp,"%d",&n);
    for (int i=0;i<n;i++){
        gets(tmp);
        string S=tmp;
        s[S.size()].pb(S);
        maxsize=max(maxsize,(int)S.size());
        sumlen+=S.size();   
    }
    int one=sumlen/(n/2);
    one++;
    char delim;
    cin>>delim;
    for (int i=1;i<=maxsize;i++){
        sort(s[i].begin(),s[i].end());
        reverse(s[i].begin(),s[i].end());
    }
    memset(tmp,0,sizeof(tmp));
    for (int i=0;2*i<n;i++){
        int best;
        if (delim < 'a'){
            best=-1;
            for (int j=1;j<=maxsize;j++)
                if (s[j].size())
                    if (best==-1 || cmp(s[j].back(),s[best].back()))
                        best=j;                 
        }
        else {
            best=-1;
            for (int j=maxsize;j>=1;j--)
                if (s[j].size())
                    if (best==-1 || cmp(s[j].back(),s[best].back()))
                        best=j;                         
        }
        for (int i=0;i<one;i++)
            tmp[i]=0;
        sprintf(tmp,"%s",s[best].back().data());
        int len=s[best].back().size();
        s[best].pop_back();
        tmp[len++]=delim;
        sprintf(tmp+len,"%s",s[one-len].back().data());
        puts(tmp);
        s[one-len].pop_back();      
    }
    return 0;
}