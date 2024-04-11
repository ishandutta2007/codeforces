#include <bits/stdc++.h>
using namespace std;
int n,cur,i,j,ops,pos,x;
vector<int> st,len;
pair<int,int> ans[500500];
void solve(int le, int ri, int p) {
  for (int j=0; j<p; j++) for (int i=le; i+(1<<j)<ri; i++)
    if ((i%(1<<(j+1)))<(1<<j)) ans[ops++]={i,i+(1<<j)};
}
int main() {
  scanf("%d",&n);
  for (i=18; i>=0; i--) if ((n>>i)&1) {
    solve(cur,cur+(1<<i),i);
    st.push_back(cur);
    len.push_back(1<<i);
    cur+=(1<<i);
  }
  if (len.size()>2) {
    x=int(len.size())-2;
    pos=st.back();
    cur=len.back();
    while (x>0) if (len[x]==cur) {
      for (j=0; j<cur; j++) ans[ops++]={st[x]+j,(pos+j)%n};
      cur*=2;
      pos=st[x--];
    } else {
      for (j=0; j<cur; j++) ans[ops++]={(pos+j)%n,(pos+j+cur)%n};
      cur*=2;
    }
  }
  printf("%d\n",ops);
  for (i=0; i<ops; i++) printf("%d %d\n",ans[i].first+1,ans[i].second+1);
  return 0;
}