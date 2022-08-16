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
#define all(x) x.begin(),x.end()
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define precise(x) fixed << setprecision(x) 

int ask(int l,int r)
{
    cout <<"? " << l << ' ' << r << endl;
    cin >> l;
    return l;
}

void solve(int mx,int l,int r)
{
    if(l == r)
    {
        cout << "! " << l << endl;
        exit(0);
    }
    
    if(r == l + 1)
    {
        if(ask(l,r) == l) solve(mx,r,r);
        else solve(mx,l,l);
    }
    
    int mid = (l + r)/2;
    
    if(mx <= l)
    {
        if(ask(mx,mid) == mx) solve(mx,l,mid);
        else solve(mx,mid+1,r);
    }
    else if(ask(mid,mx) == mx) solve(mx,mid,r);
    else solve(mx,l,mid-1);
}

signed main()
{
    int n;
    cin >> n;
    
    int l = 1;
    int r = n;
    int res = -1;
    int pos = ask(1,n);
    
    if(pos == 1 || pos == n) solve(pos,1,n);
    else if(ask(1,pos) == pos) solve(pos,1,pos);
    else solve(pos,pos,n);
}