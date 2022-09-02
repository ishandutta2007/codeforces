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

vector<int> a;
vector<int> b;
int base;

bool get(vector<int>& a,int b){
    a.clear();
    for (;b;b/=10){
        a.pb(b%10);
        if (a.back()>=base) return false;
    }
    return true;
}

int solve(int A,int B){
    if (!get(a,A)) return 0;
    if (!get(b,B)) return 0;
    int asz=a.size();
    int bsz=b.size();
    int c=0;
    for (int i=0;;i++){
        if (i>=asz && i>=bsz && c==0) return i;
        if (i<asz) c+=a[i];
        if (i<bsz) c+=b[i];
        c/=base;
    }
    assert(false);
}


int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int a,b,ans;
    cin>>a>>b;
    ans=0;
    for (base=1;base<50;++base)
        ans=max(ans,solve(a,b));
    cout<<ans<<endl;    
    return 0;
}