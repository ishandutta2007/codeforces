#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;

int n,k, wall[2][100100];
string s[2];
bool b=0;

int main(){
  scanf("%d%d", &n, &k);
  cin>>s[0]>>s[1];
  
  memset(wall, -1, sizeof wall);

  wall[0][0]=0;
  priority_queue<pair<int, int> > Q;
  Q.push(make_pair(0, 0));

  for (;!Q.empty();) {
    pair<int,int>r=Q.top(); Q.pop();
    int t=-r.first, h=r.second/2, m=r.second%2;

    if (h+1 == n || h+k>=n) { b=1; break; }
    
    if (t<h-1 && s[m][h-1]!='X' && (wall[m][h-1]==-1 || wall[m][h-1]>t+1)) {
      wall[m][h-1]=t+1;
      Q.push(make_pair(-t-1, h*2-2+m));
    }

    if (s[m][h+1]!='X' && (wall[m][h+1]==-1 || wall[m][h+1]>t+1)) {
      wall[m][h+1]=t+1;
      Q.push(make_pair(-t-1, h*2+2+m));
    }
    if (s[!m][h+k]!='X' && (wall[!m][h+k]==-1 || wall[!m][h+k]>t+1)) {
      wall[!m][h+k]=t+1;
      Q.push(make_pair(-t-1, h*2+2*k+(!m)));
    }
  }

  puts(b?"YES":"NO");

  return 0;
}