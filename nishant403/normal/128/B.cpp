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
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define precise(x) fixed << setprecision(x) 
 
int n;
vi sa;
 
vector<int> sort_cyclic_shifts(string const& s) 
{
    int n = s.size();
    const int alphabet = 256;
    
    vector<int> p(n), c(n), cnt(max(alphabet, n), 0);
    for (int i = 0; i < n; i++)
        cnt[s[i]]++;
    for (int i = 1; i < alphabet; i++)
        cnt[i] += cnt[i-1];
    for (int i = 0; i < n; i++)
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i-1]])
            classes++;
        c[p[i]] = classes - 1;
    }
    
    vector<int> pn(n), cn(n);
    for (int h = 0; (1 << h) < n; ++h) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++)
            cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i-1];
        for (int i = n-1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
            if (cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}
 
string ss;
 
void create(string & s)
{
    ss = s;
    s += '$';   
    sa = sort_cyclic_shifts(s);
    sa.erase(sa.begin());
}
 
vector<int> lcp_construction(string const& s, vector<int> const& p) {
    int n = s.size();
    vector<int> rank(n, 0);
    for (int i = 0; i < n; i++)
        rank[p[i]] = i;
 
    int k = 0;
    vector<int> lcp(n-1, 0);
    for (int i = 0; i < n; i++) {
        if (rank[i] == n - 1) {
            k = 0;
            continue;
        }
        int j = p[rank[i] + 1];
        while (i + k < n && j + k < n && s[i+k] == s[j+k])
            k++;
        lcp[rank[i]] = k;
        if (k)
            k--;
    }
    return lcp;
}
 
const int N = 1e5 + 10;
const int LN = 17;
int lg[N];
int sp[LN][N];
 
//LCP of suffix L to R
int get(int l,int r)
{
    if(l > r) swap(l,r);
    if(l == r) return n-sa[l];
    r--;
    int p = lg[r-l+1];
    return min(sp[p][l],sp[p][r-(1<<p)+1]);
}
 
//Find smaller strings for suffix array index i and length j
int find(int i,int j)
{
    int res = 0;
    
    for(int k=0;k<n;k++)
    {
        int gg = get(k,i);
        
        if(gg >= j) res += j;
        else if(k < i) res += n - sa[k];
        else res += gg;
    }
    
    return res;
}
 
signed main()
{
    fast;
 
    string s;
    cin >> s;
    
    n = s.length();
    
    create(s);
    
    vector<int> lcp = lcp_construction(ss,sa);
    
    for(int i=2;i<=n;i++) lg[i] = (lg[i-1] + !(i & (i-1)));
 
    for(int i=0;i<n-1;i++) sp[0][i] = lcp[i];
    
    for(int i=1;i<LN;i++)
        for(int j=0;j<n-1;j++)
          if(j + (1LL<<(i-1)) < n-1) 
             sp[i][j] = min(sp[i-1][j] , sp[i-1][j + (1LL<<(i-1))]);
        
    int l = 0;
    int r = n-1;
    int res = -1;
    
    int k;
    cin >> k;
    
    if((n*(n+1))/2 < k)
    {
        cout <<"No such line.";
        exit(0);
    }
    
    while(l <= r)
    {
        int mid = (l + r)/2;
        
        if(find(mid,n - sa[mid]) < k) 
        {
            l = mid + 1;
        }
        else        
        {
            res = mid;
            r = mid - 1;
        }
    }
    
    //Now binary search on length for string in res
    l = 1;
    r = n - sa[res];
    
    int res2 = -1;
    
    while(l <= r)
    {
        int mid = (l+r)/2;
        
        if(find(res,mid) < k)
        {
            l = mid + 1;
        }
        else
        {
            res2 = mid;
            r = mid - 1;
        }
    }
    
    for(int i=0;i<res2;i++)
        cout << ss[sa[res]+i];
}