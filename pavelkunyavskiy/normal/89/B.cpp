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

typedef unsigned long long int64;
typedef long double ld;


struct widget{
  int64 x,y;
  int type;
  vector<widget*> in;
  int64 br,sp;  
  bool done;
  void calc(){
    if (type == -1)
      return;
    if (done)
      return;    
    done = true;
    x=y=0;
    for (int i=0;i<in.size();i++){      
      in[i]->calc();
      if (type == 0){
    x += in[i]->x + sp*(!!i);
    y = max(y,in[i]->y);
      }
      if (type == 1){
    y += in[i]->y + sp*(!!i);
    x = max(x,in[i]->x);
      }
    }      
    
    if (in.size()){
      x+=2*br;
      y+=2*br;
    }
    else 
      x=y=0;
  }
  widget(){
    x=y=type=br=sp=0;
    done = 0;
    in.clear();
  }
};

map<string,widget*> v;

char buf[10000];
char buf2[10000];
char buf3[10000];

int main(){
  #ifdef LOCAL  
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    string s;
    getline(cin,s);
    int m;
    sscanf(s.data(),"%d",&m);
    for (int i=0;i<m;i++){
      gets(buf);
      int x,y;
      if (sscanf(buf," Widget %[a-z] ( %d , %d )",buf2,&x,&y) == 3){
    widget* tmp = new widget();
    tmp->x = x;
    tmp->y = y;
    tmp->type = -1;
    v[string(buf2)] = tmp;
    continue;
      }
      if (sscanf(buf," VBox %s",buf2) == 1){
    widget* tmp = new widget();
    tmp->type = 1;
    v[string(buf2)] = tmp;
    continue;
      }
      if (sscanf(buf," HBox %s",buf2) == 1){
    widget* tmp = new widget();
    tmp->type = 0;  
    v[string(buf2)] = tmp;
    continue;
      }
      if (sscanf(buf," %[a-z] . pack ( %[a-z] )",buf2,buf3) == 2){
    assert(v.find(string(buf2)) != v.end()); 
    assert(v.find(string(buf3)) != v.end()); 
    v[string(buf2)]->in.pb(v[string(buf3)]);
    continue;
      }
      if (sscanf(buf," %[a-z] . set_border ( %d )",buf2,&x) == 2){
    assert(v.find(string(buf2)) != v.end());
    v[string(buf2)]->br = x;
    continue;
      }
      if (sscanf(buf," %[a-z] . set_spacing ( %d )",buf2,&x) == 2){
    assert(v.find(string(buf2)) != v.end()); 
    v[string(buf2)]->sp = x;
    continue;
      }      
      assert(false);
    }
    
    for (map<string,widget*>::iterator iter = v.begin();iter != v.end();++iter){
      iter->second->calc();
      cout << iter->first <<" "<<iter->second->x <<" "<<iter->second->y<<endl;
    }
    return 0;
}