#include<cstdio>
#include<algorithm>
using namespace std;
int x,t,a,b,d,e;


int main(){
  scanf("%d%d%d%d%d%d", &x,&t,&a,&b,&d,&e);
  for (int i=0; i<t; i++) {
    if (x==0 || x==a-i*d || x==b-i*e) {
      puts("YES");
      return 0;
    }
    for (int j=0; j<t; j++) {
      if (x==a-i*d+b-j*e) {
	puts("YES");
	return 0;
      }
    }
  }
  puts("NO");
  return 0;
}