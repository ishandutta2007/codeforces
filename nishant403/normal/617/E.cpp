#include <bits/stdc++.h>
using namespace std;
 
#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

const int N = 1e5+10;
const int M = 1048578;

int n,m,k;
int a[N];
int ans = 0;
int aa[M];

void add(int idx)
{
    aa[a[idx]]++;
    ans+=aa[a[idx]^k];
    
    if(k == 0)ans--;
}

void remove(int idx)
{
   ans-=aa[a[idx]^k];
   aa[a[idx]]--;
    
   if(k==0) ans++;
}

int get_answer()
{
   return ans;   
}

int block_size = 300;

struct Query {
    int l, r, idx;
    bool operator<(Query other) const
    {
        return make_pair(l / block_size, r) <
               make_pair(other.l / block_size, other.r);
    }
};

vector<int> mo(vector<Query> & queries) {
    vector<int> answers(queries.size());
    sort(queries.begin(), queries.end());
    
    int cur_l = 0;
    int cur_r = -1;
  
   for (Query q : queries) {
        while (cur_l > q.l) {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < q.r) {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < q.l) {
            remove(cur_l);
            cur_l++;
        }
        while (cur_r > q.r) {
            remove(cur_r);
            cur_r--;
        }
       
       
        answers[q.idx] = get_answer();
    }
    return answers;
}

void solve()
{
  cin >> n >> m >> k;
    
  f(i,n) cin >> a[i+1];
  for(int i=1;i<=n;i++) a[i]^=a[i-1];  
    
  vector<Query> qq(m);
    
  f(i,m) cin >> qq[i].l >> qq[i].r;
    
  f(i,m) qq[i].idx = i; 
  f(i,m) qq[i].l--; 
    
  auto v =  mo(qq);
    
 for(auto x : v) cout << x <<"\n";
}

signed main()
{
    fast;
    solve();
}