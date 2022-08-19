    //~ while (clock()<=69*CLOCKS_PER_SEC)
    //~ #pragma comment(linker, "/stack:200000000")
    #pragma GCC optimize("O3")
    //~ #pragma GCC target ("avx2")
    //~ #pragma GCC optimize("Ofast")
    //~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
    //~ #pragma GCC optimize("unroll-loops")
    #include <bits/stdc++.h>
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>
     
    using namespace __gnu_pbds;
    using namespace std;
     
    template <typename T>
    using ordered_set =
        tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
     
    #define sim template < class c
    #define ris return * this
    #define dor > debug & operator <<
    #define eni(x) sim > typename \
      enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
    sim > struct rge { c b, e; };
    sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
    sim > auto dud(c* x) -> decltype(cerr << *x, 0);
    sim > char dud(...);
    struct debug {
    #ifdef LOCAL
    ~debug() { cerr << endl; }
    eni(!=) cerr << boolalpha << i; ris; }
    eni(==) ris << range(begin(i), end(i)); }
    sim, class b dor(pair < b, c > d) {
      ris << "(" << d.first << ", " << d.second << ")";
    }
    sim dor(rge<c> d) {
      *this << "[";
      for (auto it = d.b; it != d.e; ++it)
        *this << ", " + 2 * (it == d.b) << *it;
      ris << "]";
    }
    #else
    sim dor(const c&) { ris; }
    #endif
    };
    #define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
     
    #define shandom_ruffle random_shuffle
     
    using ll=long long;
    using pii=pair<int,int>;
    using pll=pair<ll,ll>;
    using vi=vector<int>;
    using vll=vector<ll>;
    const int nax=8007;
    using bn=bitset<nax>;
    ll inf;
     
    int n;
     
    bn tab[nax];
     
    int czym=0;
    int czas;
    int post[nax];
    int bylo[nax];
     
    int k;
    vi spo[nax];
     
    ll wyn;
     
    void dfs(int v)
    {
    	if (bylo[v])
    		return;
    	bylo[v]=1;
    	for (int i=1; i<=n; i++)
    		if (tab[v][i])
    			dfs(i);
    	czas++;
    	post[czas]=v;
    }
     
    void dfs2(int v)
    {
    	if (bylo[v])
    		return;
    	bylo[v]=1;
    	spo[czym].push_back(v);
    	for (int i=1; i<=n; i++)
    		if (tab[v][i])
    			dfs2(i);
    }
     
    void care(int v)
    {
    	int r=spo[v].size();
    	if (r==1)
    		return;
    	vi wek=spo[v];
    	vi kol;
    	kol.push_back(wek.back());
    	wek.pop_back();
    	while(!wek.empty())
    	{
    		int x=kol.back();
    		int kto=-1;
    		for (int i : wek)
    			if (tab[i][x])
    				if (kto==-1 || tab[kto][i])
    					kto=i;
    		kol.push_back(kto);
    		for (int &i : wek)
    		{
    			if (i==kto)
    			{
    				swap(i, wek.back());
    				wek.pop_back();
    				break;
    			}
    		}
    	}
    	reverse(kol.begin(), kol.end());
    	
    	debug() << imie(kol);
    	vi dal(r);
    	for (int i=0; i<r; i++)
    	{
    		while(tab[kol[i]][kol[(i+dal[i]+1)%r]])
    			dal[i]++;
    	}
    	debug() << imie(dal);
    	for (int i=0; i<r; i++)
    	{
    		debug() << i;
    		int v=0;
    		int ter=0;
    		while(v<r-1)
    		{
    			ter++;
    			int dod=dal[(i+v)%r];
    			dod=min(dod, r-1-v);
    			//~ debug() << ter << " " << dod;
    			wyn+=ter*dod;
    			v+=dod;
    		}
    	}
    }
     
    int main()
    {
    	scanf("%d", &n);
    	getchar();
    	for (int i=1; i<=n; i++)
    	{
    		for (int j=1; j<=n/4; j++)
    		{
    			char c=getchar();
    			int l;
    			if (c>='0' && c<='9')
    				l=c-'0';
    			else
    				l=c-'A'+10;
    			//~ debug() << imie(c) << " " << imie(l);
    			for (int g=0; g<4; g++)
    			{
    				tab[i][4*j-g]=(l>>g)&1;
    			}
    		}
    		getchar();
    	}
    	//~ for (int i=1; i<=n; i++)
    	//~ {
    		//~ for (int j=1; j<=n; j++)
    			//~ printf("%d", (int)(tab[i][j]));
    		//~ printf("\n");
    	//~ }
    	inf=614*n;
    	for (int i=1; i<=n; i++)
    		dfs(i);
    	for (int i=1; i<=n; i++)
    		bylo[i]=0;
    	for (int h=1; h<=n; h++)
    	{
    		int v=post[h];
    		if (bylo[v])
    			continue;
    		czym++;
    		dfs2(v);
    	}
    	k=czym;
    	for (int i=1; i<=k; i++)
    		debug() << spo[i];
    	for (int i=1; i<=k; i++)
    		for (int j=i+1; j<=k; j++)
    			wyn+=spo[i].size()*spo[j].size()*(inf+1);
    	//~ for (int i=1; i<=k; i++)
    		//~ care(i);
    	care(1);
    	
    	printf("%lld\n", wyn);
    	return 0;
    }