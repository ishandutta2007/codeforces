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

#define TASKNAME "G"

typedef long long ll;
typedef long double ld;

char p[15][2100];
int l[15];
int r[15];
char s[2100];
int n;

vector<int> pfunc(string s,string t){
    string res = s + '$' + t;
    vector<int> p(res.size());
    for (int i = 1; i < (int)res.size(); i++){
        int j = p[i-1];
        while (j && res[j] != res[i]){
            j = p[j-1];
        }
        if (res[j] == res[i])
            j++;
        p[i] = j;
    }
    vector<int> cnt(s.size()+1);
    for (int i = (int)s.size()+1; i < (int)res.size(); i++){
        assert(p[i] <= (int)s.size());
        cnt[p[i]]++;
    }

    for (int i = (int)s.size(); i > 0; i--)
        cnt[p[i-1]] += cnt[i];

/*  eprintf("%s %s\n",s.data(),t.data());
    for (int i = 0; i < (int)cnt.size(); i++)
        eprintf("%d ",cnt[i]);
    eprintf("\n");*/


    return cnt;
}

vector<int> cnts[15];

bool check(int len){
    for (int i = 0; i < n; i++)
        if (!(l[i] <= cnts[i][len] && cnts[i][len] <= r[i]))
            return 0;
    return 1;
}

int lcp[2100];

int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif
    scanf("%s",s);
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
        scanf("%s %d %d",p[i],&l[i],&r[i]);
    
    int ans = 0;

    int slen = strlen(s);

    for (int i = slen-1; i>=0; i--){
        for (int j = 0; j < n; j++)
            cnts[j] = pfunc(s+i,p[j]);
        for (int j = 0; j < slen; j++)
            lcp[j] = (s[i] == s[j])?lcp[j+1]+1:0;
//      eprintf("%s %d\n",s+i,i?*max_element(lcp,lcp+i):0);
        for (int len = (i?*max_element(lcp,lcp+i):0)+1; s[i+len-1]; len++){
            ans += check(len);
        }
    }

    printf("%d\n",ans);
      
    TIMESTAMP(end);
    return 0;
}