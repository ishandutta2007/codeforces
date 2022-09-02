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

int t[110][110][15];
int a[110][110];
int n,m,k;

void gen(int x,int y,int ost){
//  cerr<<x<<" "<<y<<" "<<ost<<endl;
    if (x==0){
        printf("%d\n",y+1);
        return;
    }
    int ost1=ost;
    ost-=a[x][y];
    ost+=1000*k;
    ost%=k;
    if (y==0){  
        gen(x-1,y+1,ost);
        printf("L");
        return;
    }
    if (y==m-1){
        gen(x-1,y-1,ost);
        printf("R");
        return; 
    }
    if (t[x-1][y+1][ost]+a[x][y]==t[x][y][ost1]){
        gen(x-1,y+1,ost);
        printf("L");
        return; 
    }
    gen(x-1,y-1,ost);
    printf("R");
    return;     
}


int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    cin>>n>>m>>k;
    k++;
    for (int i=n-1;i>=0;i--)
        for (int j=0;j<m;j++)
            {
                char c;
                scanf(" %c ",&c);
                a[i][j]=c-'0';
            }
    for (int x=0;x<n;x++)
        for (int i=0;i<m;i++)
            for (int j=0;j<k;j++)
                t[x][i][j]=-(1<<29);
    for (int i=0;i<m;i++)
        t[0][i][a[0][i]%k]=a[0][i];

        
        
    for (int i=1;i<n;i++){
        for (int j=0;j<m;j++)
            for (int l=0;l<k;l++){
                if (j!=0)
                    t[i][j][l]=max(t[i][j][l],t[i-1][j-1][(l-a[i][j]+1000*k)%k]+a[i][j]);
                if (j!=m-1)
                    t[i][j][l]=max(t[i][j][l],t[i-1][j+1][(l-a[i][j]+1000*k)%k]+a[i][j]);
            //  cerr<<i<<" "<<j<<" "<<l<<" "<<t[i][j][l]<<endl;
            }               
        }   
    
    int ans=-(1<<29);
    for (int i=0;i<m;i++)
        ans=max(ans,t[n-1][i][0]);
    if (ans<0){
        printf("-1\n");
        return 0;
    }
    cout<<ans<<endl;
    for (int i=0;i<m;i++)
        if (t[n-1][i][0]==ans){
            gen(n-1,i,0);
            return 0;
        }
    return 0;
}