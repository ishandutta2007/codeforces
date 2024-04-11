#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define dep(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int maxn=3e5+5;
const ll mo=998244353;
ll gcd(ll x,ll y){return y==0?x:gcd(y,x%y);}
ll power(ll a,ll n){ll sum=1; while(n){if(n&1) sum=sum*a%mo; n>>=1; a=a*a%mo;} return sum;}
int n,m,k;
int a[maxn],c[maxn],num[maxn],fg[maxn];
int ans,tmp,cnt;
string s,t;
int l[maxn],r[maxn];
int get(char ch){return (ch-'a');}
int main()
{
    int T,cas=1;
    cin>>s>>t;
    int n=s.length(),m=t.length();
    int pos=0,fg=1;
    memset(a,-1,sizeof(a));
    rep(i,0,n-1)
	{
	    if(pos<m&&s[i]==t[pos])
	    a[get(s[i])]=++pos;
	    l[i]=a[get(s[i])];
	}
	memset(a,-1,sizeof(a));
	pos=m-1;
	dep(i,n-1,0)
	{
	    if(pos>=0&&s[i]==t[pos])
	    a[get(s[i])]=pos--;
	    r[i]=m-a[get(s[i])];
	}
	fg=1;
	rep(i,0,n-1)
	{
        if(l[i]<=0||r[i]>m||l[i]+r[i]-1<m)
        fg=0;
	}
	if(!fg) cout<<"No";
	else cout<<"Yes";
}