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

bool checkluck(int x){
    if (x == 0)
        return false;
    for (;x;x/=10)
        if (x%10 != 4 && x%10 != 7)
            return false;
    return true;
}

const int MAXN = 110000;

int a[MAXN];
pair<int,int> b[MAXN];

int rpos[MAXN];
int pos[MAXN];
vector<pair<int,int> > ans;
                            

void change(int p1,int p2){
    if (p1 == p2)
        return;
    ans.pb(mp(p1+1,p2+1));                 
    
    swap(rpos[pos[p1]],rpos[pos[p2]]);
    swap(pos[p1],pos[p2]);
}

void changeval(int a,int b){
    change(rpos[a],rpos[b]);
}



int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int n;
    scanf("%d",&n);
    int luckid = -1;
    for (int i = 0; i < n;i++){
        scanf("%d",&a[i]);
        if (checkluck(a[i]))
            luckid = i;
    }

    if (luckid == -1){
        for (int i = 1; i < n; i++)
            if (a[i] < a[i-1]){
                printf("-1\n");
                return 0;
            }
        printf("0\n");
        return 0;                
    }

    for (int i=0; i < n; i++){
        pos[i] = rpos[i] = i;
        b[i] = mp(a[i],i);
    }

    sort(b,b+n);


    for (int i = 0; i < n; i++){
        int to = b[i].second;
        if (to == luckid)
            continue;

        changeval(pos[i],luckid);
        changeval(luckid,to); 
    }

    printf("%d\n",int(ans.size()));
    for (int i = 0; i < ans.size(); i++)
        printf("%d %d\n",ans[i].first,ans[i].second);     

    return 0;
}