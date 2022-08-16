#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd> & a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (cd & x : a)
            x /= n;
    }
}
    
vector<int> multiply(vector<int> const& a, vector<int> const& b) 
{
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<int> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}

const int N = 125005;

map<int,int> graph[N][6];
int vis[N][6];
int ans[N];

int dfs(int id,int ch)
{
    vis[id][ch] = 1;
    
    int res = 1;
    
    for(auto x : graph[id][ch]) 
        if(!vis[id][x.F]) res+=dfs(id,x.F);
        
   return res;
}

void solve()
{
    string a,b;
    cin >> a >> b;
    
    int n = a.length();
    int m = b.length();
    
    vi check1[6],check2[6];
    
    f(i,6)
    {
       check1[i].resize(n);
       f(j,n) check1[i][j] = (a[j] == ('a'+i));  
       
       check2[i].resize(m);
       f(j,m) check2[i][j] = (b[j] == ('a'+i));
        
       reverse(check2[i].begin(),check2[i].end()); 
    }
    
    for(int i=0;i<6;i++)
      for(int j=0;j<6;j++)
      {
        if(i==j) continue;
        
          auto v = multiply(check1[i],check2[j]);
        
          for(int k=m-1;k<n;k++)
          {
            if(v[k] > 0)
            {
                graph[k-(m-1)][i][j] = 1; 
                graph[k-(m-1)][j][i] = 1;
            }
          }
      }
    
    f(i,n-m+1) 
        f(j,6) if(!vis[i][j]) ans[i]+=dfs(i,j)-1;
    
    f(i,n-m+1) cout << ans[i] <<" ";
    
}

signed main()
{
    fast;
    solve();
}