#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

typedef long long LL;

int n;

int gcd(int a, int b) { return b?gcd(b, a%b):a; }


int main(){
  scanf("%d", &n);
  int k, b;
  set<pair<int, int> > se;
  for (int i=0; i<n; i++) {
    scanf("%d%d", &k, &b);
    if (k==0) continue;
    if (b==0) k=1;
    int g, p=1;
    if (k<0) p*=-1, k*=-1;
    if (b<0) p*=-1, b*=-1;
    g=gcd(k, b);
    se.insert(make_pair(k/g*p, b/g*p));
  }
  printf("%d\n", se.size());
  return 0;
}