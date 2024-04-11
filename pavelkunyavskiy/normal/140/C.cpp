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

typedef long long ll;
typedef long double ld;


set<pair<int,int>,greater<pair<int,int> > > s;
map<int,int> cnt;
int n;

void norm(pair<pair<int,int>,int>& a){
    if (a.second > a.first.first)
        swap(a.second,a.first.first);
    if (a.second > a.first.second)
        swap(a.second,a.first.second);
    if (a.first.second > a.first.first)
        swap(a.first.second,a.first.first);
}

int main()
{
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    scanf("%d",&n);
    for (int i = 0; i < n; i++){
        int a;
        scanf("%d",&a);
        if (cnt.find(a) == cnt.end()){
            cnt[a] = 1;
            s.insert(mp(1,a));
        }
        else {
            s.erase(mp(cnt[a],a));
            cnt[a]++;
            s.insert(mp(cnt[a],a));
        }
    }

    vector<pair<pair<int,int>,int> > ans;


    for (;s.size() > 2;){
        pair<int,int> a = *s.begin();
        s.erase(s.begin());
        pair<int,int> b = *s.begin();
        s.erase(s.begin());
        pair<int,int> c = *s.begin();
        s.erase(s.begin());

        ans.pb(mp(mp(a.second,b.second),c.second));
        norm(ans.back());
        
        --a.first;
        --b.first;
        --c.first;

        if (a.first > 0)
            s.insert(a);
        if (b.first > 0)
            s.insert(b);
        if (c.first > 0)
            s.insert(c);
    }

    cout << ans.size() << endl;

    for (int i = 0; i < ans.size(); i++)
        printf("%d %d %d\n",ans[i].first.first,ans[i].first.second,ans[i].second);  
    return 0;
}