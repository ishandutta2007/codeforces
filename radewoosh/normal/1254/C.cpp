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
    const int nax=1000*1007;
    const ll inf=1e18;
     
    void ff()
    {
    	fflush(stdout);
    }
     
    ll pyt1(int a, int b, int c)
    {
    	printf("1 %d %d %d\n", a, b, c);
    	ff();
    	ll x;
    	scanf("%lld", &x);
    	return x;
    }
     
    int pyt2(int a, int b, int c)
    {
    	printf("2 %d %d %d\n", a, b, c);
    	ff();
    	int x;
    	scanf("%d", &x);
    	return x;
    }
     
    int n;
     
    vi licz(int a, int b, vi wek)
    {
    	vector <pair<ll,int> > dos;
    	for (int i : wek)
    		dos.push_back({pyt1(a, b, i), i});
    	sort(dos.begin(), dos.end());
    	
    	vi ret, pom;
    	int ost=dos.back().second;
    	for (auto i : dos)
    	{
    		int v=i.second;
    		if (v==ost || pyt2(a, ost, v)==-1)
    			ret.push_back(v);
    		else
    			pom.push_back(v);
    	}
    	while(!pom.empty())
    	{
    		ret.push_back(pom.back());
    		pom.pop_back();
    	}
    	return ret;
    }
     
    int main()
    {
    	scanf("%d", &n);
    	vi raz, dwa;
    	for (int i=3; i<=n; i++)
    	{
    		if (pyt2(1, 2, i)==1)
    			raz.push_back(i);
    		else
    			dwa.push_back(i);
    	}
    	vi w1=licz(2, 1, raz);
    	vi w2=licz(1, 2, dwa);
    	printf("0");
    	printf(" 1");
    	for (int i : w2)
    		printf(" %d", i);
    	printf("\n");
    	printf(" 2");
    	for (int i : w1)
    		printf(" %d", i);
    	ff();
    	return 0;
    }