//#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <bitset>
#define mp make_pair
#define pb push_back

#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("["#x"] Time : %.3lf s.\n", clock()*1.0/CLOCKS_PER_SEC)
#define TIMESTAMPf(x,...) eprintf("[" x "] Time : %.3lf s.\n", __VA_ARGS__, clock()*1.0/CLOCKS_PER_SEC)

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

#define TASKNAME "B"

typedef long long ll;
typedef long double ld;

struct Move{
    vector<int> v;
    vector<ll> cost;

    Move(int n):v(n,-1),cost(n,-1){
//      for (int i = 0; i < n; i++) 
//          v[i] = i, cost[i] = 0;
    }
};

Move operator*(const Move& a,const Move& b){
    Move res(a.v.size());
    assert(a.v.size() == b.v.size());
    for (int i = 0; i < (int)a.v.size(); i++){
        if (a.v[i] != (int)a.v.size()-1){
            res.v[i] = b.v[a.v[i]+1];
            res.cost[i] = b.cost[a.v[i]+1]+a.cost[i];
        } else {
            res.v[i] = b.v[0];
            res.cost[i] = b.cost[0]+a.cost[i] + 1;
        }
    }
    return res;
}

Move operator^(const Move& a,int b){
    Move temp = a;
    Move res = a;
    b--;
    for (int i = 0; (1LL<<i) <= b; i++){
        if (b & (1<<i))
            res = res * temp;
        temp = temp * temp;
    }
    return res;
}

char s[200],t[200];



int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif
    int a,b;
    gets(s);
    sscanf(s,"%d %d",&a,&b);

    gets(s);
    gets(t);

    for (int i = 0; t[i]; i++){
        bool ok = false;
        for (int j = 0; s[j]; j++)
            ok |= s[j] == t[i];
        if (!ok){
            printf("0\n");
            return 0;
        }
    }

    Move one(strlen(s));
    for (int i = 0; s[i]; i++){
        int ptr = i-1, cnt = 0;
        for (int j = 0; t[j]; j++){
            do {
                ptr++;
                if (!s[ptr]){
                    ptr = 0;
                    cnt++;
                }
            } while (s[ptr] != t[j]);
        }
        one.v[i] = ptr;
        one.cost[i] = cnt;
    }

//      for (int i = 0; s[i]; i++)
//          eprintf("%d -> %d "LLD"\n",i,one.v[i],one.cost[i]);
    
//      eprintf("!! %d\n",b);
    one = one ^ b;

//      for (int i = 0; s[i]; i++)
//          eprintf("%d -> %d "LLD"\n",i,one.v[i],one.cost[i]);

    int p = 0;
    for (int i = 30; i >= 0; i--){
        if ((one ^ (p + (1<<i))).cost[0] < a){
            p += (1<<i);
        }
    }

    printf("%d\n",p);
      
    TIMESTAMP(end);
    return 0;
}