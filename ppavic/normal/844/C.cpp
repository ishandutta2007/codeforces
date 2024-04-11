#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1e5 + 500;

int bio[N],a[N],n;
vector < int > saz;
vector < int > grupe[N];
int koja = 0;

void sazimanje(){
  for(int i = 0;i<n;i++){
    saz.push_back(a[i]);
  }
  sort(saz.begin(),saz.end());
  for(int i = 0;i<n;i++)
    a[i] = lower_bound(saz.begin(),saz.end(),a[i]) - saz.begin();
}

int main(){
  scanf("%d",&n);
  for(int i = 0;i<n;i++){
    scanf("%d",a+i);
  }
  sazimanje();
  for(int i = 0;i<n;i++){
    if(bio[i]) continue;
    int cur = i;
    while(!bio[cur]){
      bio[cur] = 1;
      grupe[koja].push_back(cur);
      cur = a[cur];
    }
    koja++;
  }
  printf("%d\n",koja);
  for(int i = 0;i<koja;i++){
    printf("%d ",grupe[i].size());
    sort(grupe[i].begin(),grupe[i].end());
    for(int j = 0;j<grupe[i].size();j++)
      printf("%d ",grupe[i][j]+ 1);
    printf("\n");
  }
  return 0;

}