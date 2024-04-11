    //~ while (clock()<=69*CLOCKS_PER_SEC)
    //~ #pragma comment(linker, "/stack:200000000")
    #pragma GCC optimize("O3")
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
    const int nax=10*1007;
     
    int n;
    int sta[nax];
    int kon[nax];
     
    char wcz[nax];
     
    int ile[3];
     
    int ter[nax];
     
    vi wyn;
     
    void obr(int v)
    {
    	wyn.push_back(v);
    	reverse(ter+1, ter+1+v);
    	for (int i=1; i<=v; i++)
    		if (abs(ter[i])==1)
    			ter[i]*=-1;
    }
     
    void test()
    {
    	scanf("%s", wcz+1);
    	n=strlen(wcz+1);
    	for (int i=1; i<=n/2; i++)
    	{
    		int a=wcz[2*i-1]-'0';
    		int b=wcz[2*i]-'0';
    		sta[i]=a+b;
    		if (a>b)
    			sta[i]=-1;
    	}
    	scanf("%s", wcz+1);
    	for (int i=1; i<=n/2; i++)
    	{
    		int a=wcz[2*i-1]-'0';
    		int b=wcz[2*i]-'0';
    		kon[i]=a+b;
    		if (a>b)
    			kon[i]=-1;
    	}
    	ile[0]=ile[1]=ile[2]=0;
    	for (int i=1; i<=n/2; i++)
    	{
    		ile[abs(sta[i])]++;
    		ile[abs(kon[i])]--;
    	}
    	if (ile[0] || ile[1] || ile[2])
    	{
    		printf("-1\n");
    		return;
    	}
    	wyn={-1};
    	while((int)wyn.size()>n || ((int)wyn.size()==1 && wyn[0]==-1))
    	{
    		wyn.clear();
    		for (int i=1; i<=n/2; i++)
    			ter[i]=sta[i];
    		int v=n/2;
    		while(v)
    		{
    			if (ter[v]==kon[v])
    			{
    				v--;
    				continue;
    			}
    			if (kon[v]==0 || kon[v]==2)
    			{
    				if (ter[1]==kon[v])
    				{
    					obr(v);
    					continue;
    				}
    				vi gdz;
    				for (int i=1; i<=v; i++)
    					if (ter[i]==kon[v])
    						gdz.push_back(i);
    				int x=gdz[rand()%gdz.size()];
    				obr(x);
    				obr(v);
    				continue;
    			}
    			if (ter[1]==-kon[v])
    			{
    				obr(v);
    				continue;
    			}
    			vi gdz;
    			for (int i=1; i<=v; i++)
    				if (ter[i]==kon[v])
    					gdz.push_back(i);
    			if (!gdz.empty())
    			{
    				int x=gdz[rand()%gdz.size()];
    				obr(x);
    				obr(v);
    				continue;
    			}
    			for (int i=1; i<=v; i++)
    				if (-ter[i]==kon[v])
    					gdz.push_back(i);
    			int x=gdz[rand()%gdz.size()];
    			obr(x);
    			obr(1);
    			obr(v);
    		}
    	}
    	printf("%d\n", (int)wyn.size());
    	for (int i : wyn)
    		printf("%d ", 2*i);
    	printf("\n");
    }
     
    int main()
    {
    	int t;
    	scanf("%d", &t);
    	while(t--)
    		test();
    	return 0;
    }