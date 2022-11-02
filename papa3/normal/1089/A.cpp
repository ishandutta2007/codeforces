#include<bits/stdc++.h>
#define FOR(i,s,e) for(int i=(s); i<=(e); i++)
#define FORD(i,s,e) for(int i=(s); i>=(e); i--)
#define e1 first
#define e2 second
#define pb push_back
#define eb emplace_back


using namespace std;
typedef long long LL;
typedef pair<int,int> PII;

bool check30(int a, int b, vector<PII>& res30){ // as - winners
  if (a < 75) return false;
  int sa[] = {25, 25, 25};
  int sb[] = {0, 0, 0};
  a -= 75;
  if (a > 0){
    sa[0] += a;
    a = 0;
    sb[0] = sa[0] - 2;
    b -= sb[0];
    if (b < 0) return false;
  } else{
    sb[0] = min(23, b);
    b -= sb[0];
  }
  FOR(i,1,2) {
    sb[i] = min(23, b);
    b -= sb[i];
  }
  if (a != 0 || b != 0) return false;
  FOR(i,0,2) res30.eb(sa[i], sb[i]);
  return true;
}

bool check31(int a, int b, vector<PII>& res31){
  int sa[] = {0, 25, 25, 25};
  int sb[] = {25, 0, 0, 0};
  a -= 75;
  b -= 25;
  if (a < 0 || b < 0) return false;
  if (a <= 23 && b <= 3 * 23){
    sa[0] = a;
    a = 0;
    FOR(i,1,3) {
      sb[i] = min(23, b);
      b -= sb[i];
    }
  }
  else if (a - 23 >= b - 3 * 23){
    sa[0] = a;
    sb[0] += a - 23;
    b -= a - 23;
    a = 0;
    if (b < 0) return false;
    FOR(i,1,3) {
      sb[i] = min(23, b);
      b -= sb[i];
    }
  } else {
    sb[1] = 23;
    sb[2] = 23;
    sb[3] = 23;
    b -= 3*23;
    sb[1] += b;
    sa[1] += b;
    a -= b;
    b = 0;
    if (a < 0) return false;
    sa[0] = min(a,23);
    a -= sa[0];
  }
  if (a != 0 || b != 0) return false;
  FOR(i,0,3) res31.eb(sa[i], sb[i]);
  return true;
}


bool check32(int a, int b, vector<PII>& res){
  int sa[] = {0, 0, 25, 25, 15};
  int sb[] = {25, 25, 0, 0, 0};
  a -= 65;
  b -= 50;
  if (a < 0 || b < 0) return false;
  if (a <= 2 * 23 && b <= 2 * 23 + 13){
    FOR(i,0,1){
      sa[i] = min(23,a);
      a -= sa[i];
    }
    FOR(i,2,3) {
      sb[i] = min(23, b);
      b -= sb[i];
    }
    sb[4] = min(13, b);
    b -= sb[4];
  }
  else if (a - 2 * 23 >= b - 2 * 23 - 13){
    sa[1] = 23;
    a -= 23;
    sa[0] = a;
    sb[0] += a - 23;
    b -= a - 23;
    a = 0;
    if (b < 0) return false;
    FOR(i,2,3) {
      sb[i] = min(23, b);
      b -= sb[i];
    }
    sb[4] = min(13, b);
    b -= sb[4];
  } else {
    sb[2] = 23;
    sb[3] = 23;
    sb[4] = 13;
    b -= 2*23+13;
    sb[2] += b;
    sa[2] += b;
    a -= b;
    b = 0;
    if (a < 0) return false;
    sa[0] = min(a,23);
    a -= sa[0];
    sa[1] = min(a, 23);
    a -= sa[1];
  }
  if (a != 0 || b != 0) return false;
  FOR(i,0,4) res.eb(sa[i], sb[i]);
  return true;
}
   
main(){
  int m; scanf("%d", &m);
  while(m--){
    int a, b; scanf("%d%d", &a,&b);
    
    vector<PII> res30, res31, res32;
    bool ok30 = check30(a, b, res30);
    if (ok30){
      puts("3:0");
      for(auto it : res30){
        printf("%d:%d ",it.e1, it.e2);
      }
      puts("");
      continue;
    }
    bool ok31 = check31(a, b, res31);
    if (ok31){
      puts("3:1");
      for(auto it : res31){
        printf("%d:%d ",it.e1, it.e2);
      }
      puts("");
      continue;
    }
    bool ok32 = check32(a, b, res32);
    if (ok32){
      puts("3:2");
      for(auto it : res32){
        printf("%d:%d ",it.e1, it.e2);
      }
      puts("");
      continue;
    }
    bool ok23 = check32(b, a, res32);
    if (ok23){
      puts("2:3");
      for(auto it : res32){
        printf("%d:%d ",it.e2, it.e1);
      }
      puts("");
      continue;
    }
    bool ok13 = check31(b, a, res31);
    if (ok13){
      puts("1:3");
      for(auto it : res31){
        printf("%d:%d ",it.e2, it.e1);
      }
      puts("");
      continue;
    }
    bool ok03 = check30(b, a, res30);
    if (ok03){
      puts("0:3");
      for(auto it : res30){
        printf("%d:%d ",it.e2, it.e1);
      }
      puts("");
      continue;
    }
    puts("Impossible");
  }
}