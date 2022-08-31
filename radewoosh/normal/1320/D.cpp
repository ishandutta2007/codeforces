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
    const int nax=1000*1007;
    const ll mod=1000*1000*1000+7;
    const int n1=(1<<18);
     
    int n;
    char wcz[nax];
     
    int tab[nax];
     
    int q;
    int sa[nax];
    int sb[nax];
    int dlu[nax];
     
    int wyn[nax];
     
    struct f
    {
    	ll a=0, b=0;
    	f()
    	{
    		
    	}
    };
     
    f operator *(f x, f y)
    {
    	f ret=f();
    	ret.a=(x.a*y.a)%mod;
    	ret.b=(x.b*y.a+y.b)%mod;
    	return ret;
    }
     
    bool operator == (f x, f y)
    {
    	return x.a==y.a && x.b==y.b;
    }
     
    f jak[2];
    f pus;
     
    f drz[nax];
     
    f czyt(int v, int a, int b, int graa, int grab)
    {
    	if (a>=graa && b<=grab)
    	{
    		return drz[v];
    	}
    	if (a>grab || b<graa)
    	{
    		return pus;
    	}
    	return
    		czyt((v<<1), a, (a+b)>>1, graa, grab)*czyt((v<<1)^1, (a+b+2)>>1, b, graa, grab);
    }
     
    f daj(int a, int b)
    {
    	return czyt(1, 1, n1, a, b);
    	//~ f sta=pus;
    	//~ for (int i=a; i<=b; i++)
    		//~ sta=sta*jak[tab[i]];
    	//~ return sta;
    }
     
    int main()
    {
    	scanf("%d", &n);
    	scanf("%s", wcz+1);
    	for (int i=1; i<=n; i++)
    		tab[i]=wcz[i]-'0';
    	
    	
    	{
    		srand(time(0));
    		ll x=0;
    		while(x<=10)
    			x=rand()%1000000;
    		jak[1].a=mod-1;
    		jak[1].b=x;
    		
    		x=0;
    		while(x<=10)
    			x=rand()%1000000;
    		jak[0].a=x;
    		x=0;
    		while(x<=10)
    			x=rand()%1000000;
    		jak[0].b=x;
    		
    		pus.a=1;
    		pus.b=0;
    	}
    	
    	for (int i=1; i<=n; i++)
    		drz[n1-1+i]=jak[tab[i]];
    	for (int i=n1-1; i; i--)
    		drz[i]=drz[i*2]*drz[i*2+1];
    	
    	scanf("%d", &q);
    	for (int i=1; i<=q; i++)
    	{
    		scanf("%d%d%d", &sa[i], &sb[i], &dlu[i]);
    		
    		wyn[i]=(daj(sa[i], sa[i]+dlu[i]-1)==daj(sb[i], sb[i]+dlu[i]-1));
    	}
    	
    	
    	
    	
    	for (int i=1; i<=q; i++)
    	{
    		if (wyn[i])
    			printf("yes\n");
    		else
    			printf("no\n");
    	}
    	return 0;
    }