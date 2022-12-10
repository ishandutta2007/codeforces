//In the Name of God
//Ya Ali

#include <bits/stdc++.h>

#define robot pair<int, pair<int, pair<int, int> > >
//            pair<q , <x, <l, r> > >

#define q first
#define x second.first
#define l second.second.first
#define r second.second.second

#define err(A) cout << #A << " = " << (A) << endl

using namespace std;

const int maxn = 500300;

int n, k;

robot a[maxn];

vector<int> asl[maxn], asx[maxn], asr[maxn];

vector<int> X;

long long ans;

int id(int xx)
{
  return lower_bound(X.begin(), X.end(), xx) - X.begin() + 1;
}

int fen[maxn];

void add(int xx, int d)
{
  //cout << "ADD " << xx << " " << d << endl;
  for (; xx < maxn; xx += xx & -xx)
    fen[xx] += d;
}

void cal(int ll, int rr)
{
  //cout << "CAL " << ll << " " << rr << endl;
  for (; rr; rr -= rr & -rr)
    ans += fen[rr];
  for (-- ll; ll; ll -= ll & -ll)
    ans -= fen[ll];
}

void solve(int ls, int rs)
{
  //cout << endl << endl;
  //cout << "SOLVE " << ls << " " << rs << endl;
  //err(ans);
  
  int gq = a[ls].q;

  //err(gq);

  vector<int> all;
  
  for (int i = ls; i < rs; i ++)
    {
      asl[a[i].l].push_back(i);
      asx[a[i].x].push_back(i);
      asr[a[i].r].push_back(i);

      all.push_back(a[i].l);
      all.push_back(a[i].x);
      all.push_back(a[i].r);
    }

  sort(all.begin(), all.end());
  all.resize(unique(all.begin(), all.end()) - all.begin());

  for (int i: all)
    {
      //        err(i);
      for (int j: asx[i])
	{
	  //  err(a[j].q);
	  if (a[j].q == gq)
	    cal(a[j].l, i);
	  add(i, +1);
	}
      for (int j: asr[i])
	add(a[j].x, -1);
    }

  //err(ans);

  reverse(all.begin(), all.end());

  for (int i: all)
    {
      //err(i);
      reverse(asx[i].begin(), asx[i].end());
      for (int j: asx[i])
	{
	  //err(a[j].q);
	  if (a[j].q == gq)
	    cal(i, a[j].r);
	  if (a[j].q != gq)
	    add(i, +1);
	}
      for (int j: asl[i])
	if (a[j].q != gq)
	  add(a[j].x, -1);

      asl[i].resize(0);
      asx[i].resize(0);
      asr[i].resize(0);
    }

  //err(ans);
}

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n >> k;

  for (int i = 0; i < n; i ++)
    cin >> a[i].x >> a[i].r >> a[i].q;

  sort(a, a + n);

  //cout << "all " << endl;
  //for (int i = 0; i < n; i ++)
    //  cout << a[i].x << " " << a[i].r << " " << a[i].q << endl;
  //cout << endl;

  for (int i = 0; i < n; i ++)
    X.push_back(a[i].x), X.push_back(a[i].x - a[i].r), X.push_back(a[i].x + a[i].r);

  sort(X.begin(), X.end());
  X.resize(unique(X.begin(), X.end()) - X.begin());

  //cout << "X :  " << endl;
  //for (int dd: X)
  //  cout << dd << " ";
  //cout << endl << endl;
  
  //cout << "HERE" << endl;

  for (int i = 0; i < n; i ++)
    {
      a[i].l = id(a[i].x - a[i].r);
      a[i].r = id(a[i].x + a[i].r);
      a[i].x = id(a[i].x);
    }

  //cout << "all " << endl;
  //for (int i = 0; i < n; i ++)
  //  cout << a[i].x << " " << a[i].l << " " << a[i].r << " " << a[i].q << endl;
  //cout << endl;

  //cout << "HERE" << endl;
  
  for (int lst, li = 0, ri = 1; li < n; )
    {
      
      for (; ri < n and a[ri].q <= a[li].q + k; ri ++);
      
      solve(li, ri);

      int cur = a[li].q;

      for (; li < n and a[li].q == cur; li ++);
    }

  cout << ans << endl;
  
  return 0;
}