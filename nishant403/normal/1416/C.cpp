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

typedef struct data
{
	data* bit[2];
	int cnt = 0;
}trie;

trie* head;

void insert(int x)
{
	trie* cur = head;
    
	for(int i=30;i>=0;i--)
	{
		int b = (x>>i) & 1;
		if(!cur->bit[b]) cur->bit[b] = new trie();
		cur = cur->bit[b];
		cur->cnt++;
	}
}

const int BT = 31;
int go[BT][2];

void query(int x)
{
    trie* cur = head;
    
    for(int i=30;i>=0;i--)
    {
        int b = (x>>i) & 1;
        
        if(cur->bit[b^1] != NULL) go[i][b] += cur->bit[b^1]->cnt;
        if(!cur->bit[b]) return;
        cur = cur->bit[b];
    }
}

void solve()
{
   head = new trie(); 
    
   int n;
    cin >> n;
    
   int a[n];
    f(i,n) cin >> a[i];
    
   for(int i=0;i<n;i++)
   {
       query(a[i]);
       insert(a[i]);
   }
    
   int res = 0;
   int num = 0; 
    
   for(int i=0;i<BT;i++)
   {
       if(go[i][0] <= go[i][1])
       {
          res+=go[i][0];
       }
       else
       {
          res+=go[i][1];
          num|=(1LL<<i); 
       }
   }
    
   cout << res << ' ' << num; 
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}