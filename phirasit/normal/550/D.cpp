#include <stdio.h>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

vector<pii> ls1, ls2;
vector<pii> edge;
int cnt = 1;
int k;

int main() {
  scanf("%d", &k);
  
  if(k%2 == 0) {
    printf("NO\n");
    return 0;
  }

  printf("YES\n");
  cnt = 2;
  for(int i = 0;i < k/2;i++) {
    ls1.push_back({cnt, cnt+1});
    ls2.push_back({cnt+2, cnt+3});

    edge.push_back({1, cnt});
    edge.push_back({1, cnt+1});
    edge.push_back({cnt, cnt+2});
    edge.push_back({cnt, cnt+3});
    edge.push_back({cnt+1, cnt+2});
    edge.push_back({cnt+1, cnt+3});
    edge.push_back({cnt+2, cnt+3});

    cnt += 4;
  }
  for(int i = 0;i < ls1.size();i++) {
    for(int j = 0;j < i;j++) {
      edge.push_back({ls1[i].first, ls1[j].first});
      edge.push_back({ls1[i].first, ls1[j].second});
      edge.push_back({ls1[i].second, ls1[j].first});
      edge.push_back({ls1[i].second, ls1[j].second});
      edge.push_back({ls2[i].first, ls2[j].first});
      edge.push_back({ls2[i].first, ls2[j].second});
      edge.push_back({ls2[i].second, ls2[j].first});
      edge.push_back({ls2[i].second, ls2[j].second});
    }
  }

  int x = cnt;
  edge.push_back({1, x});
  cnt = cnt+1;

  ls1.clear();
  ls2.clear();
  for(int i = 0;i < k/2;i++) {
    ls1.push_back({cnt, cnt+1});
    ls2.push_back({cnt+2, cnt+3});

    edge.push_back({x, cnt});
    edge.push_back({x, cnt+1});
    edge.push_back({cnt, cnt+2});
    edge.push_back({cnt, cnt+3});
    edge.push_back({cnt+1, cnt+2});
    edge.push_back({cnt+1, cnt+3});
    edge.push_back({cnt+2, cnt+3});

    cnt += 4;

  }
  for(int i = 0;i < ls1.size();i++) {
    for(int j = 0;j < i;j++) {
      edge.push_back({ls1[i].first, ls1[j].first});
      edge.push_back({ls1[i].first, ls1[j].second});
      edge.push_back({ls1[i].second, ls1[j].first});
      edge.push_back({ls1[i].second, ls1[j].second});
      edge.push_back({ls2[i].first, ls2[j].first});
      edge.push_back({ls2[i].first, ls2[j].second});
      edge.push_back({ls2[i].second, ls2[j].first});
      edge.push_back({ls2[i].second, ls2[j].second});
    }
  }

  printf("%d %d\n", cnt-1, (int)edge.size());
  for(pii p : edge) {
    printf("%d %d\n", p.first, p.second);
  }
  return 0;
}