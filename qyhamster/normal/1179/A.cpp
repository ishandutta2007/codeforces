#include <iostream>
#include <algorithm>
#include <cstring>
#define int int64_t
using namespace std;
int a[100010],t[100010];
int ans[100010][2];
struct deque {
  int a[300010], lcnt{100011},rcnt{100010};
  deque() {memset(a,0,sizeof(a));}
  int front() {
    return a[lcnt];
  }
  void pop_front() {lcnt++;}
  void pop_back() {rcnt--;}
  void push_front(int x) {a[--lcnt] = x;}
  void push_back(int x) {a[++rcnt] = x;}
}dq;
int32_t main()
{
  int n,Q;
  cin >> n >> Q;
  int mx = 0;
  for(int i = 0; i < n; i++)
  {
    cin >> a[i];
    mx = max(mx, a[i]);
    dq.push_back(a[i]);
  }
  int cnt = 0;
  while(dq.front() != mx)
  {
    int x = dq.front();
    dq.pop_front();
    int y = dq.front();
    dq.pop_front();
    ans[cnt][0] = x;
    ans[cnt][1] = y;
    if(x < y)swap(x,y);
    dq.push_back(y);
    dq.push_front(x);
    cnt++;
  }
  dq.pop_front();
  for(int i = 0; i < n-1; i++)
  {
    t[i] = dq.front();
    dq.pop_front();
  }
  while(Q--)
  {
    long long q;
    cin >> q;
    q--;
    if(q < cnt)
    {
      cout << ans[q][0] << " " << ans[q][1] << endl;
      continue;
    }
    else
    {
      q -= cnt;
      long long x = q % (n-1);
      cout << mx << " " <<  t[x] << endl;
    }
  }
  return 0;
}