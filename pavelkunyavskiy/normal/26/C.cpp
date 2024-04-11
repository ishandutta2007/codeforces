#include <iostream>
#include <cassert>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <memory.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iterator>

#define mp make_pair
#define pb push_back

#ifdef __WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

typedef long long int64;
typedef long double ld;

int col[150][150];
char colc[150][150];
int n,m;
int n0,m0;
int a,b,c;

#define NO "IMPOSSIBLE\n"

void error()
{
    printf(NO);
    exit(0);
}

void nechet(){
    if (n%2==1 && m%2==1)
        error();
    if (n%2==1){
        int need=m/2;
        if (a<need)
            error();
        a-=need;
        for (int i=0;i<m;i++)
            col[n-1][i]=1;
        --n;
        return;         
    }
    if (m%2==1){
        int need=n/2;
        if (b<need)
            error();
        b-=need;
        for (int i=0;i<n;i++)
            col[i][m-1]=2;
        --m;
        return;
    }
    return;
}

void chet(){
    a-=a%2;
    b-=b%2;
    int s=a*2+b*2+c*4;
    if (s<n*m)
        error();
    int i,j;
    i=j=0;
    for (;i<n && a;){
        col[i][j]=col[i+1][j]=col[i][j+1]=col[i+1][j+1]=1;
        a-=2;
        j+=2;
        if (j==m){
            i+=2;
            j=0;
        }
    }
    for (;i<n && b;){
        col[i][j]=col[i+1][j]=col[i][j+1]=col[i+1][j+1]=2;
        b-=2;
        j+=2;
        if (j==m){
            i+=2;
            j=0;
        }
    }
    for (;i<n && c;){
        col[i][j]=col[i+1][j]=col[i][j+1]=col[i+1][j+1]=3;
        --c;
        j+=2;
        if (j==m){
            i+=2;
            j=0;
        }
    }
    assert(i==n);
}

void gen(){
    n=n0;
    m=m0;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++){
        //  cerr<<i<<" "<<j<<" "<<col[i][j]<<endl;
            if (col[i][j]==1){
                int v=(i+(j/2))%2;
                colc[i][j]=colc[i][j+1]='a'+v;
                col[i][j]=col[i][j+1]=0;
            }
            if (col[i][j]==2){
                int v=(i/2+j)%2;
                colc[i][j]=colc[i+1][j]='c'+v;
                col[i][j]=col[i+1][j]=0;
            }
            if (col[i][j]==3){
                int v=(i/2+j/2)%2;
                colc[i][j]=colc[i+1][j]=colc[i][j+1]=colc[i+1][j+1]='e'+v;
                col[i][j]=col[i+1][j]=col[i][j+1]=col[i+1][j+1]=0;              
            }                                                     
            
        }
}

void print(){
    for (int i=0;i<n;i++)
        {                                                
            for (int j=0;j<m;j++){
                printf("%c",colc[i][j]);
                assert(colc[i][j]>='a' && colc[i][j]<='f');
            }
            printf("\n");
        }     
}



int main(){ 
    cin>>n>>m>>a>>b>>c;
    n0=n;
    m0=m;
    nechet();
    if (n>0 && m>0)
        chet();
    gen();
    print();
    return 0;
}