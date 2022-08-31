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
     
    int n;
     
    int tab[nax];
     
    vi tso[nax];
     
    pii wyn;
     
    int mam;
     
    vi wyp[nax];
     
    void cons(pii v)
    {
    	if (v.first*v.second>wyn.first*wyn.second)
    		wyn=v;
    }
     
    map <int,int> ile;
     
    int main()
    {
    	scanf("%d", &n);
    	for (int i=1; i<=n; i++)
    	{
    		scanf("%d", &tab[i]);
    		ile[tab[i]]++;
    		tso[ile[tab[i]]].push_back(tab[i]);
    	}
    	for (int i=1; i*i<=n; i++)
    	{
    		mam+=(int)tso[i].size();
    		if (mam>=i*i)
    			cons({i, mam/i});
    	}
    	ile.clear();
    	vector <pii> wek;
    	printf("%d\n%d %d\n", wyn.first*wyn.second, wyn.second, wyn.first);
    	int a=wyn.first;
    	int b=wyn.second;
    	swap(a, b);
    	for (int i=0; i<a; i++)
    		wyp[i].resize(b);
    	for (int i=1; i<=wyn.first; i++)
    	{
    		for (int j : tso[i])
    		{
    		    if ((int)wek.size()==a*b)
    		        continue;
    			ile[j]++;
    			wek.push_back({0, j});
    		}
    	}
    	for (pii &i : wek)
    		i.first=ile[i.second];
    	sort(wek.begin(), wek.end());
    	reverse(wek.begin(), wek.end());
    	int x=0;
    	int y=0;
    	for (pii h : wek)
    	{
    		int i=h.second;
    		if (wyp[x][y])
    			x=(x+1)%a;
    		assert(!wyp[x][y]);
    		wyp[x][y]=i;
    		x=(x+1)%a;
    		y=(y+1)%b;
    	}
    	for (int i=0; i<a; i++)
    	{
    		for (int j : wyp[i])
    			printf("%d ", j);
    		printf("\n");
    	}
    	return 0;
    }