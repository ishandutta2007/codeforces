#include <cstdio>
#include <string>
#include <vector>
using namespace std;
int a[4],i;
vector <string> r;
void print(char c, int i) {
  string s="##";
  s[0]=c; s[1]=i+'0';
  r.push_back(s);
}
void put(string s) { r.push_back(s); }
int main() {
  scanf("%d%d%d%d",&a[0],&a[1],&a[2],&a[3]);
  for (i=0; i<2; i++) while (a[i]!=1) {
    if (a[i]&1) {
      print('+',i+1);
      a[i]++; a[i+1]++;
    }
    if (a[i+1]&1) {
      print('+',i+2);
      a[i+1]++; a[i+2]++;
    }
    print('/',i+1);
    a[i]>>=1; a[i+1]>>=1;
    if (r.size()>1000) { puts("-1"); return 0; }
  }
  while (a[2]>2 || a[3]>2) {
     if ((a[2]&1) && (a[3]&1)) {
       put("+3"); a[2]++; a[3]++;
     } else if ((a[2]&1)==0 && (a[3]&1)==0) {
       put("/3"); a[2]>>=1; a[3]>>=1;
     } else if ((a[2]&1)==0 && (a[3]&1)) {
       put("+4"); a[3]++; a[0]++;
       put("/3"); a[2]>>=1; a[3]>>=1;
       put("+2"); a[2]++; a[1]++;
       put("/1"); a[0]>>=1; a[1]>>=1;
     } else {
       put("+2"); a[2]++; a[1]++;
       put("/3"); a[2]>>=1; a[3]>>=1;
       put("+4"); a[3]++; a[0]++;
       put("/1"); a[0]>>=1; a[1]>>=1;
     }
     if (r.size()>1000) { puts("-1"); return 0; }
  }
  if (a[2]==2 && a[3]==2) put("/3"); else if (a[2]==2) {
    put("+2"); put("+3"); put("/2"); put("/3");
  } else if (a[3]==2) {
    put("+3"); put("+4"); put("/3"); put("/4");
  }
  for (i=0; i<r.size(); i++) puts(r[i].c_str());
  return 0;
}