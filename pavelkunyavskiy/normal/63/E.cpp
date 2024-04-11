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

const int kol[7]={0,0,3,4,5,4,3};
const int sdv[7]={0,0,0,0,0,1,2};

int pos[10][10];
int x[19];
int y[19];

void gen(){
    memset(pos,-1,sizeof(pos));
    int cnt=0;
    for (int i=0;i<7;i++)
        for (int j=sdv[i];j<sdv[i]+kol[i];j++){
            pos[i][j]=cnt;
            x[cnt]=i;
            y[cnt++]=j;
        }
}

int ans[1<<20];

int solve(int mask){    
    if (mask==0)
        return 0;
    if (ans[mask]!=-1)
        return ans[mask];
    ans[mask]=0;
    for (int i=0;i<19 && !ans[mask];i++){
        if ((mask & (1<<i))==0)
            continue;
        int mask1=0;
        int x=::x[i];
        int y=::y[i];
        //cerr<<"!!!"<<endl;
        for (int k=0;!ans[mask];k++){
            int x1=x;
            int y1=y+k;
            if (pos[x1][y1]!=-1 && (mask&(1<<pos[x1][y1]))){
                mask1|=(1<<pos[x1][y1]);
                ans[mask]=1-solve(mask^mask1);
            }
            else
                break;
        }
        mask1=0;
        for (int k=0;!ans[mask];k++){
            int x1=x+k;
            int y1=y;
            if (pos[x1][y1]!=-1 && (mask&(1<<pos[x1][y1]))){
                mask1|=(1<<pos[x1][y1]);
                ans[mask]=1-solve(mask^mask1);
            }
            else    
                break;
        }
        mask1=0;
        for (int k=0;!ans[mask];k++){
            int x1=x+k;
            int y1=y+k;
            if (pos[x1][y1]!=-1 && (mask&(1<<pos[x1][y1]))){
                mask1|=(1<<pos[x1][y1]);
                ans[mask]=1-solve(mask^mask1);
            }       
            else    
                break;
        }
    }
//  cerr<<mask<<" "<<ans[mask]<<endl;
    return ans[mask];
}




int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    gen();
    int stmask=0;
    for (int i=0;i<19;i++){ 
        char c;
        cin>>c;
        if (c=='O')
            stmask|=(1<<i);         
    }
    
//  cerr<<stmask<<endl;
    
    memset(ans,-1,sizeof(ans));
    int tmp=solve(stmask);
    if (tmp==0)
        printf("Lillebror\n");
    else
        printf("Karlsson\n");
    return 0;
}