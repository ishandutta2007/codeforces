#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <memory.h>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <deque>
#include <queue>
#include <list>
#include <algorithm>
#include <cmath>
#include <cassert>

#define mp make_pair
#define pb push_back

#ifdef LOCAL
  #define LLD "%lld"
  #define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
  #define LLD "%I64d"
  #define eprintf(...) ;
#endif

using namespace std;

typedef long long int64;
typedef long double ld;


struct node{
  node *next,*oth,*prev;  
  int x,y;
  bool type;
  node(int x,int y,bool type):x(x),y(y),type(type){
    next = oth = prev = 0;
  }
  node(){
    x=y=-1;
    next = oth = prev = 0;
  }
};


node* xs[5100];
node* ys[5100];
vector<char> s[5100];
vector<node*> xnode[5100];
vector<node*> ynode[5100];
int n,m;





void del(node* x){
  x->prev->next = x->next;
  x->next->prev = x->prev;
}


void init(){
  for (int i=0;i<n;i++)
    for (int j=0;j<m;j++)
      if (s[i][j] != '.'){
    node* tmp = new node(i,j,0);
    node* tmp2 = new node(i,j,1);
    (tmp->oth = tmp2)->oth = tmp;
    xnode[i].pb(tmp);
    ynode[j].pb(tmp2);
      }
}

node mem[30000];
int memptr;

node* getnode(){
    mem[memptr] = node();
    return &mem[memptr++];
}

void build(){
    memptr = 0;
  for (int i=0;i<n;i++){
    xs[i] = getnode();//new node();
    node* t = xs[i];
    for (int j=0;j<xnode[i].size();j++){
      t->next = xnode[i][j];
      xnode[i][j] ->prev = t;
      t = xnode[i][j];      
    }     
    t->next = getnode();//new node();
    t->next->prev = t;
  }
  for (int i=0;i<m;i++){
    ys[i] = getnode();//new node();
    node* t = ys[i];
    for (int j=0;j<ynode[i].size();j++){
      t->next = ynode[i][j];
      ynode[i][j] ->prev = t;
      t = ynode[i][j];      
    }     
    t->next = getnode();//new node();
    t->next->prev = t;
  }
}

void read(){
  scanf("%d %d",&n,&m);
  for (int i=0;i<n;i++){
    s[i].resize(m);
    for (int j=0;j<m;j++)
      scanf(" %c ",&s[i][j]);      
  }    
}



int calc(int x,int y){
  build();
  node* cur = xs[x];
  for (;cur->y != y;cur = cur->next);
  int cnt = 0;
  for (;cur->x != -1;){
    cnt++;
    int x = cur->x;
    int y = cur->y;
    node* next;
    if (s[x][y] == 'L' || s[x][y] == 'R')
      if (cur->type)
    cur = cur->oth;
    if (s[x][y] == 'U' || s[x][y] == 'D')
      if (!cur->type)
    cur = cur->oth;
    if (s[x][y] == 'L' || s[x][y] == 'U')
      next = cur->prev;
    else
      next = cur->next;
    del(cur->oth);
    del(cur);
    cur = next;    
  }
  return cnt;
}



int main(){
  #ifdef LOCAL  
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    read();
    init();
    int best = 0,bcnt = 0;
    for (int i=0;i<n;i++)
      for (int j=0;j<m;j++)
    if (s[i][j] != '.'){
      int tmp = calc(i,j);
      if (tmp > best)
        best = tmp,bcnt=1;
      else if (tmp == best)
        bcnt++;
    }
    cout << best << " "<<bcnt << endl;
    return 0;
}