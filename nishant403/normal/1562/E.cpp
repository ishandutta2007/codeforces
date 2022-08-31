#include <bits/stdc++.h>
using namespace std;

//problem : https://cses.fi/problemset/task/2108/
 
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

const int inf = 1e18;

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
 
void create(string s)
{
    sa.clear();
    
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

const int N = 5000 + 100;
int dp[N];
int pos[N];
int temp[N]; 

void solve()
{
    int n;
    cin >> n;
    
    string s;
    cin >> s;
    
    n = s.length();
    
    create(s);
    
    vector<int> lcp = lcp_construction(s,sa);
   
    f(i,N) dp[i] = -inf;
    
    f(i,n) pos[sa[i]] = i;
    
    f(i,n)
    {
        int len = n - i ;
     
        temp[0] = 0;
        for(int j=1;j<=len+1;j++) temp[j] = -inf;
        
        int ii = pos[i];
        int match = len;
        
        for(int j=ii-1;j>=0;j--)
        {
            match = min(match,lcp[j]);
            temp[match+1] = max(temp[match+1],dp[j] + 1); 
        }
        
        for(int j=1;j<=len;j++) temp[j] = max(temp[j],temp[j-1] + 1);
        
        dp[ii] = temp[len];
        
    }
    
    cout << *max_element(dp,dp+n) << '\n';
}

signed main()
{
    fast;
    
    int t;
    cin >> t;
    while(t--) solve();
}