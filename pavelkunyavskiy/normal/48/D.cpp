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

vector<int> pos[110000];
int ans[110000];

int main()
{                        
    int n;
    cin>>n;
    int ptr=0;
    for (int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        pos[x].pb(i);
        ptr=max(ptr,x);
    }
    int cnt=1;
    for (;ptr;){    
        for (int i=1;i<=ptr;i++){
            if (pos[i].size()==0){
                printf("-1\n");
                return 0;
            }
            ans[pos[i].back()]=cnt;
            pos[i].pop_back();
        }
        ++cnt;
        for (;ptr && pos[ptr].size()==0;--ptr);
    }
    printf("%d\n",cnt-1);
    for (int i=0;i<n;i++)
        printf("%d ",ans[i]);
    printf("\n");
    return 0;
}