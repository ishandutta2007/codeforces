#include <cstdio>

using namespace std;

int main() {
 int n; scanf("%d",&n);
 long long res=0;
for (long long i=1;i<=n;i++)
 {long long a; scanf("%I64d",&a); res+=(a-1)*i+1;};
 printf("%I64d",res);
 return 0;
}