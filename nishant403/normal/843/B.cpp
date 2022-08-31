#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int getRand(int l, int r)
{
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}

#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

int n,start,x;
int cnt = 1999;
int block = 999;

pii ask(int i)
{
  cout << "? "<<i<<endl;
  int a,b;
  cin >> a >> b;
  cnt--;
  return {a,b};
}

void ans(int z)
{
    cout << "! " << z << endl;
    exit(0);
}

map<int,int> mp;

void solve()
{
   cin >> n >> start >> x;
 
   auto v = ask(start);
   mp[start] = 1;
    
   //corner case 1 : x is less than a[0]
   if(v.F >= x)  ans(v.F);
    
   //maximum element less or equal to x  
   int dis = v.F; 
   int bestid = start; 
    
   vector<int> arr(n);
   f(i,n) arr[i] = i+1;
   
   random_shuffle(arr.begin(),arr.end());
   random_shuffle(arr.begin(),arr.end());
   random_shuffle(arr.begin(),arr.end());
   random_shuffle(arr.begin(),arr.end());
    
   f(i,min(n,block))
   {   
       int id = arr[i];
       
       v = ask(id);
       
       if(v.F <= x && v.F > dis) 
       {
           dis = v.F;
           bestid = id;
       }
   }
    
    v = {dis,bestid};
    
   //now we have to move further atmost block steps
   while(cnt > 0 && v.F < x && v.S != -1) v = ask(v.S); 
  
   if(v.F >= x) ans(v.F);
 
   ans(-1);  
}

signed main()
{
    solve();
}