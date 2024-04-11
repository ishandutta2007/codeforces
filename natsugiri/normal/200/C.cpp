#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

int n;
map<string, int>mp;

struct DATA_T {
  int w, g, m;
  string s;
};
bool operator<(DATA_T a, DATA_T b) {
  return a.w!=b.w?a.w>b.w:
    a.g-a.m!=b.g-b.m?a.g-a.m>b.g-b.m:
    a.g!=b.g?a.g>b.g:
    a.s<b.s;
}
DATA_T v[4];
int game[4];


int main(){
  string s;
  int p=0;
  for (int i=0; i<4; i++) v[i]= (DATA_T){0, 0, 0, ""};
  for (int i=0; i<5; i++) {
    int x, y, a, b;
    cin>>s;
    if (mp.count(s)) x=mp[s];
    else x=mp[s]=p++;
    v[x].s=s;
    cin>>s;
    if (mp.count(s)) y=mp[s];
    else y=mp[s]=p++;
    v[y].s=s;

    scanf("%d:%d", &a, &b);

    if (a==b) {
      v[x].w++; v[y].w++;
    } else if (a<b) {
      v[y].w+=3;
    } else v[x].w+=3;
    v[x].g+=a;
    v[y].g+=b;
    v[y].m+=a;
    v[x].m+=b;
    game[x]++; game[y]++;
  }

  for (int i=0; i<4; i++){
    if (v[i].s!="BERLAND" && game[i]==2) s=v[i].s;
  }

  
  sort(v, v+4);

  for (p=0; p<4; p++) if (v[p].s==s) break;

  int b, t;
  for (b=0; b<4; b++) {
    if (v[b].s=="BERLAND") {
      if (b<2) t=2;
      else t=0;
      break;
    }
  }
  v[b].w+=3;


  int x, y, z;
  bool flag=0;
  for (z=1; z<100; z++) {
    for (x=z; x<200; x++) {
      y=x-z;
      v[b].g+=x; v[b].m+=y;
      v[p].g+=y; v[p].m+=x;

      if (((v[0]<v[b])+(v[1]<v[b])+(v[2]<v[b])+(v[3]<v[b]))<2) flag=1;
      v[b].g-=x; v[b].m-=y;
      v[p].g-=y; v[p].m-=x;
      if (flag) break;
    }
    if (flag) break;
  }
      
  if (flag) printf("%d:%d\n", x, y);
  else puts("IMPOSSIBLE");

  return 0;
}