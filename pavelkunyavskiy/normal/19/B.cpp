#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <memory.h>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <deque>
#include <iterator>
#include <stack>
#include <algorithm>
#include <cassert>

#define pb push_back
#define mp make_pair
#define all(a) (a.begin(),a.end())

#define taskname "B"

using namespace std;

typedef long long int64;
typedef long double ld;

int64 t[2100][10000];

int64 c[2100];
int64 kol[2100];

int main(){

    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        cin>>kol[i]>>c[i];
    
    for (int j=0;j<=n;j++)
        for (int i=0;i<10000;i++)
            t[j][i]=(1LL<<60LL);
    
    t[0][5000]=0;
    
    for (int i=0;i<n;i++)
        for (int j=3000;j<=8000;j++)
        {
            t[i+1][j-1]=min(t[i+1][j-1],t[i][j]);
            t[i+1][min(8000LL,j+kol[i])]=min(t[i+1][min(8000LL,j+kol[i])],t[i][j]+c[i]);
        }
    
    int64 ans=(1LL<<60);
    
    for (int i=5000;i<=8000;i++)
        ans=min(ans,t[n][i]);
    
    cout<<ans<<endl;
    
    
    return 0;
}