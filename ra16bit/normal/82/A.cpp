#include <cstdio>
#include <string>
using namespace std;
const string c[5]={"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
int i,n;
int main() {
  scanf("%d",&n);
  for (i=1; ; i*=2) {
    if (5*i>=n) { printf("%s\n",c[(n-1)/i].c_str()); return 0; }
    n-=5*i;
  }
}