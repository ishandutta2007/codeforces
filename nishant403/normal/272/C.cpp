#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define F first
#define S second
#define pb push_back
#define f(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>
#define vi vector<int>
#define Fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)


//Thanks to : GeeksforGeeks

const int MAX = 4*100001;

int tree[MAX] = { 0 };   
int lazy[MAX] = { 0 }; 
  
void updateRangeUtil(int si, int ss, int se, int us, 
                     int ue, int diff) 
{ 
    if (lazy[si] != 0) { 
        tree[si] = lazy[si]; 
  
        if (ss != se) { 
            lazy[si * 2 + 1] = lazy[si]; 
            lazy[si * 2 + 2] = lazy[si]; 
        } 
  
        lazy[si] = 0; 
    } 
  
    if (ss > se || ss > ue || se < us) 
        return; 
  
    if (ss >= us && se <= ue) { 
        tree[si] = diff; 
  
        if (ss != se) { 
            lazy[si * 2 + 1] = diff; 
            lazy[si * 2 + 2] = diff; 
        } 
        return; 
    } 
  
    int mid = (ss + se) / 2; 
    updateRangeUtil(si * 2 + 1, ss, mid, us, ue, diff); 
    updateRangeUtil(si * 2 + 2, mid + 1, se, us, ue, diff); 
  
    tree[si] = max(tree[si * 2 + 1], tree[si * 2 + 2]); 
} 
  
void updateRange(int n, int us, int ue, int diff) 
{ 
    updateRangeUtil(0, 0, n - 1, us, ue, diff); 
} 
  
int getSumUtil(int ss, int se, int qs, int qe, int si) 
{ 
    if (lazy[si] != 0) { 
  
        tree[si] = lazy[si]; 
  
        if (ss != se) { 
            lazy[si * 2 + 1] = lazy[si]; 
            lazy[si * 2 + 2] = lazy[si]; 
        } 
  
        lazy[si] = 0; 
    } 
    if (ss > se || ss > qe || se < qs) 
        return 0; 
  
    if (ss >= qs && se <= qe) 
        return tree[si]; 
  
    int mid = (ss + se) / 2; 
    return max(getSumUtil(ss, mid, qs, qe, 2 * si + 1), 
               getSumUtil(mid + 1, se, qs, qe, 2 * si + 2)); 
} 
  
int getSum(int n, int qs, int qe) 
{ 
    return getSumUtil(0, n - 1, qs, qe, 0); 
} 
  
void constructSTUtil(int arr[], int ss, int se, int si) 
{ 
    if (ss > se) 
        return; 
  
    if (ss == se) { 
        tree[si] = arr[ss]; 
        return; 
    } 
  
    int mid = (ss + se) / 2; 
    constructSTUtil(arr, ss, mid, si * 2 + 1); 
    constructSTUtil(arr, mid + 1, se, si * 2 + 2); 
  
    tree[si] = max(tree[si * 2 + 1], tree[si * 2 + 2]); 
} 
  
void constructST(int arr[], int n) 
{ 
    constructSTUtil(arr, 0, n - 1, 0); 
} 

signed main()
{
Fast;    
    
    int n,m,w,h;
    cin >> n;
    
    int a[n];
    
    f(i,n) cin >> a[i];
    
    constructST(a,n);
    
    cin >> m;
    
    while(m--)
    {
     cin >> w >> h;   
  
     int l = getSum(n,0,w-1);   
        
     cout << l << "\n";
        
     updateRange(n,0,w-1,l+h);    
    }
    
}