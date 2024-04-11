// Thanks to robs77 for this template
/***********HEADER***************/
#include <iostream>
#include <bitset>
#include <iomanip>
#include <deque>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <list>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <set>
#include <queue>
#include <map>
#include <cstdlib>
/***********MACROS***************/
#define int long long 
#define ll  long long 
#define LL long long
#define fri(l,k) for (i=l;i<=k;i++)
#define frj(l,k) for (j=l;j>=k;j--)
#define fij(a,b,l,k) for(i=a;i<=b;i++) for(j=l;j<=k;j++)
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define endl "\n"
#define pb push_back
#define _1 first
#define _2 second
#define mxsz 1000000007
#define mxval 1e9 + 7
#define grt [](auto x,auto y){return x>y;}
#define pii pair<int,int>
#define fi first 
#define se second 
#define mod 1000000007
#define inf 100000000
/*********VARIABLE****************/
using namespace std;
typedef pair<int,int> ii;
/******************************/
char path[10100],co[4],ch[210],s[210];
 
/*********FUNCTIONS**************/
void Delete()
{
    int n=strlen(path);
    if(n!=0)
    {
        int i=n-1;
        while(i>=0&&path[i]!='/')path[i--]='\0';
        if(i>=0)path[i]='\0';
    }
}
/***********MAIN**************/
 
signed main(){ 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
 
    int n;
    cin >> n;
 
    int **A = new int*[n]();
    for(int i=0; i<n; i++)
        A[i] = new int[n]();
 
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> A[i][j];
 
    int *primary = new int[n*2]();
    int *secondary = new int[n*2]();
 
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            primary[i+j] += A[i][j];
            secondary[i-j+n] += A[i][j];
        }
    }
 
    int white_max = -1000, white_i = 0, white_j = 0, black_max = -1000, black_i = 0, black_j = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if((i + j) & 1)
            {
                if(primary[i+j] + secondary[i-j+n] - A[i][j] > white_max)
                {
                    white_max = primary[i+j] + secondary[i-j+n] - A[i][j];
                    white_i = i;
                    white_j = j;
                }
            } else {
                if(primary[i+j] + secondary[i-j+n] - A[i][j] > black_max)
                {
                    black_max = primary[i+j] + secondary[i-j+n] - A[i][j];
                    black_i = i;
                    black_j = j;
                }
            }
        }
    }
 
    cout << white_max + black_max << endl;
    cout << 1 + white_i << " " << 1 + white_j << " " << 1 + black_i << " " << 1 + black_j;
 
    delete [] secondary;
    delete [] primary;
    for(int i=0; i<n; i++)
        delete [] A[i];
    delete [] A;
 
    return 0;
}