#include <bits/stdc++.h>
using namespace std;
  
#define S second
#define F first
#define f(i,n) for(int i=1;i<=n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

const int inf = 1e9+10;
int mat[4001][4001];

vi last(4003,inf);
vi cur(4003,inf);

int cost(int i,int j)
{
    int res = mat[j][j]+mat[i-1][i-1]-mat[j][i-1]-mat[i-1][j];
    return res;
}

void calc(int l,int r,int cl,int cr)
{
    if(l > r) return;
    
    int mid = (l+r)/2;
    
    pii best = {inf,-1};

    for (int k = cl; k <= min(mid,cr); k++) 
        best = min(best, {last[k-1] + cost(k, mid), k});
 
    cur[mid] = best.F;
    int opt = best.S;
    calc(l,mid-1,cl,opt);
    calc(mid+1,r,opt,cr);
}

signed main()
{
    fast;
    int n,k;
    cin >> n >> k;

 char cc; 
   
    f(i,n) f(j,n)
{
 cin >> cc;
mat[i][j] = (cc-'0');
}    
    f(i,n) f(j,n)
    {
        mat[i][j]+=mat[i-1][j];
        mat[i][j]+=mat[i][j-1];
        mat[i][j]-=mat[i-1][j-1];
    }
    
    last[0] = 1;
    
    f(i,k) 
    {
        calc(i,n,1,n);
        swap(last,cur);
    }
    
    cout << (last[n]>>1);
}