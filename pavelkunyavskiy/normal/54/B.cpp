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


char s[100][100];

char tmp[100][100];
char tmp2[100][100];
int a,b;

void rotate180(){
    for (int i=0;i<a;i++)   
        for (int j=0;j<b;j++)
            tmp2[a-i-1][b-j-1]=tmp[i][j];
    for (int i=0;i<a;i++)
        for (int j=0;j<b;j++)
            tmp[i][j]=tmp2[i][j];
}

void rotate90(){
    assert(a==b);
    for (int i=0;i<a;i++)   
        for (int j=0;j<a;j++)
            tmp2[a-j-1][i]=tmp[i][j];
    for (int i=0;i<a;i++)
        for (int j=0;j<b;j++)
            tmp[i][j]=tmp2[i][j];
}

string genstr(){
    string res="";
    for (int i=0;i<a;i++)
        for (int j=0;j<b;j++)
            res+=tmp[i][j];
    return res;
}

string genstr(int x,int y){
    for (int i=0;i<a;i++)
        for (int j=0;j<b;j++)
            tmp[i][j]=s[i+x][j+y];
    string res=genstr();
    if (a==b){
        rotate90();
        res=min(res,genstr());
        rotate90();
        res=min(res,genstr());
        rotate90();
        res=min(res,genstr());
        return res;
    }
    rotate180();
    res=min(res,genstr());
    return res;
}

string str[5000];
int n,m;

bool check(int a,int b){
    if (n%a!=0 || m%b!=0)
        return false;
    ::a=a;
    ::b=b;
    int ptr=0;
    for (int i=0;i<n;i+=a)
        for (int j=0;j<m;j+=b)
            str[ptr++]=genstr(i,j);
            
    sort(str,str+ptr);
    if (unique(str,str+ptr)!=str+ptr)
        return false;
    return true;
}




int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
  while (scanf("%d %d",&n,&m)==2){
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            scanf(" %c ",&s[i][j]);
    int bestx=-1,besty=-1;
    int cnt=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++){         
            if (!check(i,j)) continue;
            cnt++;
            if (bestx==-1){
                bestx=i;
                besty=j;
                continue;               
            }
            if (i*j < bestx*besty){
                bestx=i;
                besty=j;
                continue;
            }
            if (i*j == bestx*besty  && i < bestx){
                bestx=i;
                besty=j;
                continue;
            }
        }
    cout<<cnt<<endl<<bestx<<" "<<besty<<endl;
  }
  return 0;
}