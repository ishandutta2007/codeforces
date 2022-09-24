#include<cstdio>
#include<string>
using namespace std;
int main(){
  int i,n;
  string s="abcd";
  scanf("%d",&n);
  for(i=0;i<n;i++){
    printf("%c",s[i%4]);
  }
  puts("");

  return 0;
}