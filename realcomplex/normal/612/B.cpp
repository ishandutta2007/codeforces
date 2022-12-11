#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 200005;
ll p[N];
ll a = 0;

int main(){
  int n;
  scanf("%i",&n);
  int k;
  for(int i = 0;i<n;i++){
    scanf("%i",&k);
    p[k] = i;
  }
  for(int i = 2;i<=n;i++){
    a += abs(p[i]-p[i-1]);
  }
  printf("%I64d\n",a);
  return 0; 
}