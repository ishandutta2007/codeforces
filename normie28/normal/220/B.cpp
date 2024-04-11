#include <bits/stdc++.h>
#define ll long long
#define for0(i,a,b) for (int i = a; i < b; i++)
#define for1(i,a,b) for (int i = a; i <= b; i++)
 
using namespace std;
 
const int N = 1e5+5;
const int M = 1e5+5;
const int MAXV = 1e5+5;
 
int blo,bl[N],m,n;
int v[N],mp[MAXV];
int sum;
int ans[M];
 
struct node
{
    int l,r;
    int id;
    bool operator < (const node& a)const{
        if (bl[l]==bl[a.l]) return r < a.r;
        return bl[l] < bl[a.l];
    }
}q[M];
 
int data[N];
void discrete(int a[],int n)
{
    for (int i=1;i<=n;i++) data[i] = a[i];
    sort(data+1,data+1+n);
    int cnt = unique(data+1,data+1+n) - data;
    for (int i=1;i<=n;i++) a[i] = lower_bound(data+1,data+1+n,a[i]) - data;
}
 
void REMOVE(int x)
{
    if (mp[v[x]]==data[v[x]]) sum--;
    mp[v[x]]--;
    if (mp[v[x]]==data[v[x]]) sum++;
}
 
void ADD(int x)
{
    if (mp[v[x]]==data[v[x]]) sum--;
    mp[v[x]]++;
    if (mp[v[x]]==data[v[x]]) sum++;
}
 
void solve()
{
    int nowl = 1,nowr = 0;
    for1(i,1,m){
        int tl = q[i].l,tr = q[i].r;
        while (nowr<tr) ADD(++nowr);
        while (nowl>tl) ADD(--nowl);
        while (nowr>tr) REMOVE(nowr--);
        while (nowl<tl) REMOVE(nowl++);
        ans[q[i].id] = sum;
    }
}
 
int main()
{
    cin>>n>>m;
    blo = sqrt(n);
    for1(i,1,n){
        cin>>v[i];
        bl[i] = (i-1)/blo+1;
    }
 
    discrete(v,n);
 
    for1(i,1,m){
        cin>>q[i].l>>q[i].r;
        q[i].id = i;
    }
    sort(q+1,q+1+m);
 
    solve();
 
    for1(i,1,m){
        cout<<ans[i]<<endl;
    }
}