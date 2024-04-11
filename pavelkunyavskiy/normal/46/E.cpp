#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <ctime>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>

#define mp make_pair
#define pb push_back

using namespace std;

typedef long long int64;
typedef long double ld;

int64 sum[1510][1510];
int a[1510][1510];
int64 t[1510][1510];
int n,m;



int main(){
    scanf("%d %d",&n,&m);
    for (int i=0;i<n;i++){
    for (int j=0;j<m;j++)
        scanf("%d",&a[i][j]);     
    }
    for (int i=0;i<n;i++){
    sum[i][0]=a[i][0];
    for (int j=1;j<m;j++)
        sum[i][j]=sum[i][j-1]+a[i][j];  
    }
    for (int i=0;i<m;i++)
    t[0][i]=sum[0][i];
    for (int j=m-2;j>=0;--j)
    t[0][j]=max(t[0][j],t[0][j+1]);
    for (int i=1;i<n;i++){  
    if (i&1){
        for (int j=0;j<m;j++)
        t[i][j]=-(1LL<<60);
        for (int j=0;j<m-1;j++)
        t[i][j]=t[i-1][j+1]+sum[i][j];
        for (int j=1;j<m;j++)
        t[i][j]=max(t[i][j],t[i][j-1]);
    }
    else {
        for (int j=0;j<m;j++)
        t[i][j]=-(1LL<<60);
        for (int j=1;j<m;j++)
        t[i][j]=t[i-1][j-1]+sum[i][j];
        for (int j=m-2;j>=0;j--)
        t[i][j]=max(t[i][j],t[i][j+1]);
    }
    //for (int j=0;j<m;j++)
      //  cerr<<t[i][j]<<" \n"[j==m-1];
    }
    cout<<max(t[n-1][0],t[n-1][m-1]);
    return 0;  
}