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

int a[4];
int p[4];
char op[4];
int64 ans;
 
void perebor(multiset<int64> res){
    int pos=4-res.size();
    if (pos==3){
        ans=min(ans,*res.begin());
        return;
    }
    vector<int64> r(res.begin(),res.end());
    for (int i=0;i<r.size();i++)
        for (int j=i+1;j<r.size();j++){
            multiset<int64> nres=res;
            nres.erase(nres.find(r[i]));
            nres.erase(nres.find(r[j]));
            if (op[pos]=='+')
                nres.insert(r[i]+r[j]);
            else
                nres.insert(r[i]*r[j]);
            perebor(nres);
        }
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    multiset<int64> res;
    for (int i=0;i<4;i++){
        int a;
        scanf("%d",&a);
        res.insert(a);
    }   
    ans=(1LL<<60LL);
    cin>>op[0]>>op[1]>>op[2];
    perebor(res);
    cout<<ans<<endl;
    return 0;
}