#include<cstdio>
#include<algorithm>
using namespace std;
int n;
char s[222];

int main(){
  int i;
  bool l,m;
  scanf("%d%s",&n,s);
  sort(s,s+n);sort(s+n,s+2*n);
  l=m=1;
  for(i=0;i<n;i++){
    if(s[i]<=s[i+n])m=0;
    if(s[i]>=s[i+n])l=0;
  }
  puts((l^m)?"YES":"NO");
  return 0;
}