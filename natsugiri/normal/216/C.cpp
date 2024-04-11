#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int n, m, k;
int a[2012];
vector<int>v;

int main(){
  scanf("%d%d%d", &n, &m, &k);
  a[0]=k;
  a[n-1]=1;
  if (k==1) {
    for (int i=n-1; i<n+m; i+=n-1) a[i]=1;
  } else {
    for (int i=n-1; i<n+m; i+=n) {
      a[i]=1;
      if (i+1!=n+m) a[i+1]=k-1;
    }
  }
  
  for (int i=0; i<n+m; i++) for (int j=0; j<a[i]; j++) v.push_back(i+1);
  printf("%d\n", v.size());
  for (int i=0; i<(int)v.size(); i++) printf("%d%c", v[i], i+1==(int)v.size()?'\n':' ');
  return 0;
}