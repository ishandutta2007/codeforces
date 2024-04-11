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
#define int64 long long
#define ld long double  
#define setval(a,v) memset(a,v,sizeof(a))
using namespace std;

string s[50];

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int n,m;
    scanf("%d %d\n",&n,&m);
    for (int i=0;i<n;i++)
        getline(cin,s[i]);
    int l=-1,r=-1,u=-1,d=-1;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            if (s[i][j]=='*')
            {
                if (l==-1 || l>j)
                    l=j;
                if (r==-1 || r<j)
                    r=j;
                if (u==-1 || u>i)
                    u=i;
                if (d==-1 || d<i)
                    d=i;                
            }
    for (int i=u;i<=d;i++)
    {
        for (int j=l;j<=r;j++)
            printf("%c",s[i][j]);
        printf("\n");
    }
  return 0;
}