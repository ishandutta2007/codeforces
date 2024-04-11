#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;


typedef long long LL;

int n, k;
LL b, a[111111];

int main(){

  scanf("%d%d", &n, &k);
  cin>>b;
  for (int i=0; i<n; i++) cin>>a[i];
  vector<pair<int, int> >v;
  for (int i=0; i<n-1; i++) v.push_back(make_pair((int)a[i], i));
  sort(v.begin(), v.end());
  LL s=0;
  for (int i=0; i<k-1; i++)
    s+=v[n-2-i].first;

  int x=n-1;
  for (int i=0; i<n-k; i++)
    if (s+v[i].first>b) x=min(x, v[i].second);
  if (s+v[n-k-1].first>b)
    for (int i=n-k-1; i<n-1; i++) x=min(x, v[i].second);

  printf("%d\n", x+1);
  return 0;
}