#include<bits/stdc++.h>
#define FOR(i,s,e) for(int i=(s); i<=(e); i++)
#define FORD(i,s,e) for(int i=(s); i>=(e); i--)
#define e1 first
#define e2 second
#define pb push_back
#define eb emplace_back


using namespace std;
typedef long long LL;


main(){
  int test; scanf("%d",&test);
  while(test--){
    int k; scanf("%d", &k);
    vector<int> days;
    int perweek = 0;
    int s[10];
    FOR(i,0,6){
      scanf("%d", &s[i]);
      int a = s[i];
      days.pb(a);
      perweek += a;
    }
    int fullweeks = (k - 1) / perweek;
    int resbase = fullweeks * 7;
    int remaining = k - fullweeks * perweek;
    int res = fullweeks * 7 + 17;
    FOR(i,0,6){
      int cur = i, rem = remaining;
      int chg = 0;
      while(rem > 0){
        cur = (cur+1)%7;
        chg++;
        if (s[cur] == 1) rem--;
      }
      res = min(res, resbase + chg);
    }
    printf("%d\n", res);     
  }
}