#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
    seed_seq seq{
        (uint64_t) chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count(),
        (uint64_t) __builtin_ia32_rdtsc(),
        (uint64_t) (uintptr_t) make_unique<char>().get()
    };
    mt19937 rng(seq);
    int prime(ll x)
    {
    	if (x<2) return 0;
    	for (int i=2;i<=sqrt(x);i++) if (x%i==0) return 0;
    	return 1;
    }
ll get_p()
{
	ll res;
	while(true)
	{
		res=uniform_int_distribution<int>(1e9, 2e9)(rng);
		if (prime(res)) return res;
	}
}

ll n,m,i,j,k,u,v,a,b,pr,ba;
ll dp[100001],match[100001];
ll trans[100001],ow[100001],hah[100001];
string s,t;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>s>>t;
    n=s.length();
    m=t.length();
    for (i=0;i<=n-m;i++)
    {
        match[i]=1;
        for (j=0;j<m;j++) if ((s[i+j]!=t[j])and(s[i+j]!='?')) {match[i]=0; break;}
    }
    pr=get_p();
    ba=uniform_int_distribution<int>(27,pr-1)(rng);
    for (i=0;i<m;i++)
    {
        if (i==0) ow[i]=1;
        else ow[i]=(ow[i-1]*ba)%pr;
        hah[i+1]=hah[i]+(ow[i]*(t[i]-96));
        hah[i+1]%=pr;
    }
    ll u=0;
    for (i=n-m;i>=0;i--)
    {
        if (i==n) dp[i]=0;
        else
        {
            if (i+m<=n) u=max(u,dp[i+m]);
            if (match[i])
            {
    //            cout<<i<<endl;
                for (j=1;j<m;j++) if ((hah[m]-hah[m-(m-j)]+pr)%pr==(hah[m-j]-hah[0]+pr)*ow[j]%pr) dp[i]=max(dp[i],dp[i+j]);
                dp[i]=max(dp[i],u);
                dp[i]++;
            
                a=max(a,dp[i]);
            }
        }
    }
    cout<<a;
}