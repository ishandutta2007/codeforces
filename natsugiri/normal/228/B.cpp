#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;
typedef long long LL;

int na, ma, nb, mb;
string a[55], b[55];

int fact(int x, int y) {
  int r=0;
  for (int i=max(0, -x); i<min(na, nb-x); i++) {
	for (int j=max(0, -y); j<min(ma, mb-y); j++) {
	  if (a[i][j]=='1' && b[i+x][j+y]=='1') r++;
	}
  }
  return r;
}

int main(){
  scanf("%d%d", &na, &ma);
  for (int i=0; i<na; i++) cin>>a[i];
  scanf("%d%d", &nb, &mb);
  for (int i=0; i<nb; i++) cin>>b[i];

  int cnt=-1, x, y;
  for (int i=-55; i<55; i++) {
	for  (int j=-55; j<55; j++) {
	  int tmp=fact(i, j);
	  if (cnt<tmp) {
		cnt=tmp; x=i; y=j;
	  }
	}
  }

  printf("%d %d\n", x, y);
  return 0;
}