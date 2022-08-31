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

const int N =2e5+10;

map<int,int> inv;

void merge(int a[],int l,int mid,int r)
{
    int nn = mid-l,i,j,k,mm = r-mid+1; 
  
    int L[nn], R[mm]; 
  
    f(i,nn)
        L[i] = a[l+i]; 
  
    f(j,mm) 
        R[j] = a[mid+j]; 
  
    i = 0, j = 0, k = l; 
    
    while (i < nn && j < mm) 
    { 
        if (L[i] < R[j]) 
        {  
            a[k++] = L[i++]; 
        } 
        else
        { 
            inv[R[j]]+=(nn-i);
            a[k++] = R[j++]; 
        }
    }
   
    while (i < nn)   
        a[k++] = L[i++]; 
    
    while (j < mm) 
        a[k++] = R[j++];
}

void mergesort(int a[],int l,int r)
{
 if(l<r)
 {
  int mid = (l+r)/2;
  mergesort(a,l,mid);   
  mergesort(a,mid+1,r);    
     
  merge(a,l,mid+1,r);   
 }
}


void solve()
{
int n,a,b,f,k;
    
string s1,s2;    
string prev;    
    
cin >> n >> a >> b >> k >> f;
 
map<pair<string,string>,int> coster;    
    
f(i,n)
{
    int cs = a;
    
   cin >> s1 >> s2;
    
    
   if(i>0)
   {
     if(prev == s1) cs = b; 
   }
    
      prev = s2;
    
   if(s1 > s2) swap(s1,s2);
    
    coster[{s1,s2}]+=cs; 
   
}
    
int ans =0;
    
priority_queue<int> P;    
    
for(auto  x : coster) P.push(x.S);    
    
while(!P.empty())
{
  auto x = P.top();
  P.pop();
    
  if(k>0 && x > f)
  { 
    ans+=f;   
    k--;
  } 
  else ans+=x;  
    
}
    
    cout << ans;
}

signed main()
{
    fast;
    solve();
}