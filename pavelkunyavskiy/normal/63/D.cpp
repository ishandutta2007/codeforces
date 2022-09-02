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

char s[150][150];

int a,b,c,d;


void makemap(){ 
    memset(s,'.',sizeof(s));
    for (int i=0;i<b;i++)
        for (int j=0;j<a;j++)
            s[i][j]='#';
    for (int i=0;i<d;i++)
        for (int j=a;j<a+c;j++)
            s[i][j]='#';
}

int x[150*150];
int y[150*150];
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};

bool check(int x,int y,int x1,int y1){
    for (int i=0;i<4;i++)
        if (x+dx[i]==x1 && y+dy[i]==y1)
            return true;
    return false;
}

bool dopts(int inv){
    int cnt=0;
    int need=a*b+c*d;
    for (int i=0;cnt<need;i++){
        if (i%2 == inv){    
            for (int j=0;j<a+c;j++)
                if (s[i][j]=='#'){
                    x[cnt]=i;
                    y[cnt++]=j;
                }
        }
        if (i%2 != inv){            
            for (int j=a+c-1;j>=0;--j)
                if (s[i][j]=='#'){
                    x[cnt]=i;
                    y[cnt++]=j;     
                }
        }
    }
    for (int i=0;i<cnt-1;i++)
        if (!check(x[i],y[i],x[i+1],y[i+1]))
            return false;
    return true;
}


int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    cin>>a>>b>>c>>d;
    makemap();  
    bool q=dopts(0);
    if (!q)
        q=dopts(1);
    
    if (!q){
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    int n;
    cin>>n;
    int ptr=0;
    for (char cr='a';cr<'a'+n;cr++){
        int v;
        cin>>v;
        for (;v;--v){
            s[x[ptr]][y[ptr]]=cr;
            ++ptr;
        }
    }
    for (int i=0;i<b || i<d;i++){
        for (int j=0;j<a+c;j++)
            printf("%c",s[i][j]);
        printf("\n");
    }
    return 0;
}