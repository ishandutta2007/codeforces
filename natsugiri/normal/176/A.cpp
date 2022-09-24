#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;

int n, m, k,a[10][100], b[10][100], c[10][100];
int v[100];

char s[128];

int main(){
  
  scanf("%d%d%d", &n, &m, &k);

  for(int j=0; j<m; j++)v[j]=0;
  
  for(int i=0; i<n; i++){
    scanf("%s", s);
    for(int j=0; j<m; j++)
      scanf("%d%d%d", &a[i][j], &b[i][j], &c[i][j]);
  }

  int ans=0;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      
      if(i==j)continue;
      vector<pair<int, int> >w;
      int tmp=0;
      
      for(int x=0; x<m; x++)
	if(c[i][x])
	  w.push_back(make_pair(a[i][x]-b[j][x], c[i][x]));

      sort(w.begin(), w.end());
      
      for(int x=0, p=0; x<k && p<w.size(); x++){
	if(w[p].first>0)break;
	tmp-=w[p].first;
	w[p].second--;
	if(w[p].second<=0)p++;
      }
      ans=max(ans, tmp);
    }
  }


  printf("%d\n", ans);
  return 0;
}