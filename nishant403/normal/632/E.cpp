#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define double long double
using base=complex<double>;
const double pi=acos(-1.000);

vector<ll> rev,a(1005,0);
vector<base> w;

ll N=0;
void pre(ll n,ll bits)
{
	if(N==n)
	{
		return;
	}
	N=n;
	rev.resize(n);
	for(int i=0,j=0;i<n;i++)
	{
		rev[i]=j;
		ll bit=(n>>1);
		for(;j&bit;bit>>=1)
		{
			j^=bit;
		}
		j^=bit;
	}
	w.resize(n);
	double ang=(2.00 * pi)/n;
	for(int i=0;i<n;i++)
	{
		w[i]=base(cos(i*ang),sin(i*ang));
	}
}
void fft(vector<base> &a)
{
	ll n=a.size();
	for(int i=0;i<n;i++)
	{
		if(i<rev[i])
		{
			swap(a[i],a[rev[i]]);
		}
	}
	for(int len=2;len<=n;len<<=1)
	{
		ll pw=(n/len);
		for(int i=0;i<n;i+=len)
		{
			for(int j=0;2*j<len;j++)
			{
				base u=a[i+j];
				base v=w[j*pw]*a[i+j+(len/2)];
				a[i+j]=u+v;
				a[i+j+(len/2)]=u-v;
			}
		}
	}
}
void multiply(vector<ll> &a,vector<ll> &b,vector<ll> &res)
{
	ll n=1,bits=0;
	vector<base> fa(a.begin(),a.end());
	vector<base> fb(b.begin(),b.end());
	while(n<2*max(a.size(),b.size()))
	{
		bits++;
		n<<=1;
	}
	pre(n,bits);
	fa.resize(n);
	fb.resize(n);
	fft(fa);
	fft(fb);
	for(int i=0;i<n;i++)
	{
		fa[i]=conj(fa[i]*fb[i]);
	}
	fft(fa);
	res.resize(n);
	for(int i=0;i<n;i++)
	{
		res[i]=round(fa[i].real()/(double)n);
        res[i]=min(res[i],1LL);
	}
}
vector<ll> power(vector<ll> &a,ll k)
{
	vector<ll> res((int)a.size(),0);
	res[0]=1;
	while(k>0)
    {
        if(k%2==1)
        {
            ll sr=res.size();
            ll sa=a.size();
            multiply(res,a,res);
            res.resize(sr+sa-1);
        }
        k>>=1;
        ll sa=a.size();
        multiply(a,a,a);
        a.resize(sa+sa-1);
    }
	return res;
}
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);  cout.tie(0);
	ll n,k,x;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
    {
        ll x;
        cin>>x;
        a[x]=1;
    }

	vector<ll> ans=power(a,k);
    for(int i=0;i<(int)ans.size();i++)
    {
        if(ans[i])
        {
            cout<<i<<' ';
        }
    }
    cout<<endl;
	return 0;
}