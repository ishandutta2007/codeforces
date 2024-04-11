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

int a[100][100];
int n,m;

int sum(int x,int y,int dx,int dy){
    if (x + dx > n) return (1<<30);
    if (y + dy > m) return (1<<30);
    int ans=0;
    for (int i=0;i<dx;i++)
        for (int j=0;j<dy;j++)
            ans+=a[x+i][y+j];
    return ans;
}

int main()
{                        
    int ans=1<<30;  
    cin>>n>>m;
    int A,B;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            cin>>a[i][j];
    cin>>A>>B;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++){
            ans=min(ans,sum(i,j,A,B));
            ans=min(ans,sum(i,j,B,A));
        }
    cout<<ans<<endl;
    return 0;
}