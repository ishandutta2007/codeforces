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

typedef unsigned long long ll;
typedef long double ld;


ll hash[2100];
ll p[2100];

ll calchash(string s){
    ll ans = 0;
    for (int i = 0; i < s.size(); i++)
        ans = ans + (s[i]-'a'+1)*p[i];
    return ans * p[2011-s.size()];
}

void inithash(string s){
    p[0] = 1;
    for (int i = 1; i < 2100; i++)
        p[i] = p[i-1]*239017;
    hash[0] = s[0]-'a'+1;
    for (int i = 1; i < s.size(); i++)
        hash[i] = hash[i-1] + p[i]*(s[i]-'a'+1);
}

ll gethash(int l,int r){
    return (hash[r] - (l?hash[l-1]:0))* p[2010 - r];
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    string a,b,c;
    cin >>a >> b >> c;
    inithash(a);
    ll h1 = calchash(b);
    ll h2 = calchash(c);


    vector<ll> ans;

    int n = a.size();
    int n1 = b.size(),n2 = c.size();

    for (int i = 0; i <= n - n1; i++)
        for (int j = i+max(n1,n2)-1;j < n; j++)
            if (gethash(i,i+n1-1) == h1 && gethash(j-n2+1,j) == h2)
                ans.pb(gethash(i,j));
    sort(ans.begin(),ans.end());
    cout << unique(ans.begin(),ans.end()) - ans.begin() << endl;
    return 0;
}