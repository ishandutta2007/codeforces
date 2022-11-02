#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,i,j;
  int arr[5000];
  scanf("%d", &n);
  for (i=0;i<n;i++)
    scanf("%d",&arr[i]);
  vector<pair<int,int> > daftar;
  for (i=0;i<n;i++)
  {
    int nummin = i;
    for(j=i;j<n;j++) {
      if (arr[j] < arr[nummin]) {
        nummin = j;
      }
    }
    daftar.push_back(make_pair(i, nummin));
    swap(arr[i], arr[nummin]);
  }
  printf("%d\n",daftar.size());
  for (pair<int,int> now : daftar) {
    printf("%d %d\n", now.first, now.second);
  }
}