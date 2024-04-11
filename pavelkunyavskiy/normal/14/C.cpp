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

int a[4][4];

void NO(){
    printf("NO\n");
    exit(0);
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
  for (int i=0;i<4;i++)
  {
    for (int j=0;j<4;j++)
        cin>>a[i][j];
    if (((a[i][0]==a[i][2]) ^ (a[i][1]==a[i][3]))==false)
        NO();
    }
    
    
    for (int i=0;i<4;i++)
        if (a[i][0]==a[i][2]){
            for (int j=0;j<4;j++)
                swap(a[i][j],a[0][j]);
            break;
        }
    for (int i=1;i<4;i++)
        if (a[i][0]==a[i][2]){
            for (int j=0;j<4;j++)
                swap(a[i][j],a[1][j]);
            break;
        }
        
        
    if (a[1][0]!=a[1][2] || a[0][0]!=a[0][2])
        NO();       
    if (a[1][0]==a[0][0] || a[2][1]==a[3][1])
        NO();
        
        
    if (a[0][1]>a[0][3])
        swap(a[0][1],a[0][3]);  
    if (a[1][1]>a[1][3])
        swap(a[1][1],a[1][3]);
    if (a[2][0]>a[2][2])
        swap(a[2][0],a[2][2]);
    if (a[3][0]>a[3][2])
        swap(a[3][0],a[3][2]);
        
        
    if (a[0][1]!=a[1][1] || a[0][3]!=a[1][3])
        NO();   
    if (a[2][0]!=a[3][0] || a[2][2]!=a[3][2])
        NO();   
        
        
    if (a[2][0]>a[2][2])
        swap(a[2][0],a[2][2]);  
    if (a[3][0]>a[3][2])
        swap(a[3][0],a[3][2]);
    if (a[2][0]!=a[3][0] || a[2][2]!=a[3][2])
        NO();

    if (a[0][0]>a[1][0])
    {
        swap(a[0][0],a[1][0]);
        swap(a[0][2],a[1][2]);
    }
    
    if (a[2][1]>a[3][1])
    {
        swap(a[2][1],a[3][1]);
        swap(a[2][3],a[3][3]);
    }
    if (a[0][1]!=a[2][1])
        NO();
    if (a[0][3]!=a[3][1])
        NO();
    if (a[2][0]!=a[0][0])
        NO();
    if (a[2][2]!=a[1][2])
        NO();
    printf("YES\n");

    return 0;
}