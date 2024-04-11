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

const int MAXN=110000;

int a[MAXN],b[MAXN];
int n;
int64 k;

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    cin>>n>>k;
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
        b[i] = a[i];
    }
    sort(b,b+n);
    for (int i=n-1;i>0;i--)
        b[i] -= b[i-1];
    int64 cnt = 0;
    vector<int> ans;
    for (int i=0;i<n;i++){
        if (b[i] * 1LL * (n-i) <= k){
            k -= b[i] * 1LL * (n-i);
            cnt += b[i];
            continue;
        }
        cnt += k/(n-i);
        k%=(n-i);
        ans.reserve(n-i);
        for (int j=0;j<n;j++){
            if (a[j] > cnt)
                ans.pb(j);
            a[j] -= cnt;
        }       
        break;
    }
    if (k > 0 && ans.size() == 0){
        printf("-1\n");
        return 0;
    }
    if (k == 0 && ans.size() == 0){
        printf("\n");
        return 0;
    }
    for (int i=0;i<k;i++)
        a[ans[i]]--;
    rotate(ans.begin(),ans.begin()+k,ans.end());
    vector<int> ans2;
    for (int i=0;i<ans.size();i++)
        if (a[ans[i]]!=0)
            ans2.pb(ans[i]);
    for (int i=0;i<ans2.size();i++)
        printf("%d ",ans2[i]+1);
    printf("\n");
    return 0;
}