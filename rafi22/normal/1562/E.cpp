#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

namespace SuffixArray
{
	const int MAXN = 1 << 21;
	string S;
	int N, gap;
	int sa[MAXN], pos[MAXN], tmp[MAXN], lcp[MAXN];

	bool sufCmp(int i, int j)
	{
		if (pos[i] != pos[j])
			return pos[i] < pos[j];
		i += gap;
		j += gap;
		return (i < N && j < N) ? pos[i] < pos[j] : i > j;
	}

	void buildSA()
	{
		N = sz(S);
		REP(i, N) sa[i] = i, pos[i] = S[i];
		for (gap = 1;; gap *= 2)
		{
			sort(sa, sa + N, sufCmp);
			REP(i, N - 1) tmp[i + 1] = tmp[i] + sufCmp(sa[i], sa[i + 1]);
			REP(i, N) pos[sa[i]] = tmp[i];
			if (tmp[N - 1] == N - 1) break;
		}
	}

	void buildLCP()
	{
		for (int i = 0, k = 0; i < N; ++i) if (pos[i] != N - 1)
		{
			for (int j = sa[pos[i] + 1]; S[i + k] == S[j + k];)
			++k;
			lcp[pos[i]] = k;
			if (k)--k;
		}
	}
}

const bool multi=1;

int DP[5007];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    if(multi)
        cin>>tt;
    else tt=1;
    while(tt--)
    {
        memset(DP,0,sizeof DP);
        int n,ans=0;
        cin>>n;
        cin>>SuffixArray::S;
        SuffixArray::buildSA();
        SuffixArray::buildLCP();
        for(int l=0;l<n;l++)
        {
            int i=SuffixArray::sa[l];
           // cout<<SuffixArray::lcp[l]<<" ";
            DP[i]=n-i;
            int mn=inf;
            for(int k=l-1;k>=0;k--)
            {
                mn=min(mn,SuffixArray::lcp[k]);
                int j=SuffixArray::sa[k];
                if(j<i)
                {
                    DP[i]=max(DP[i],DP[j]+n-i-mn);
                }
            }
            ans=max(ans,DP[i]);
        }
      //  cout<<endl;
        cout<<ans<<endl;
    }

    return 0;
}