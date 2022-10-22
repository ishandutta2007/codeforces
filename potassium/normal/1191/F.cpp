#include <bits/stdc++.h>
#define INF 2147483647
#define LLINF LLONG_MAX
#define PI 3.1415926535
#define MOD 1000000007
#define MOD2 998244353
#define SP << " "
#define EL << "\n"
#define FL << flush
#define sqr(x) ((x)*(x))
#define pb push_back
typedef long long ll;
using namespace std;
template <class T1, class T2> ostream& operator << (ostream& out, pair<T1,T2> p);
template <template <class...> class _TContainer, class... _T> ostream& operator << (ostream& out, _TContainer<_T...>& _Container);

struct disc_map{
    vector<int> NumUsed;
    map<int,int> m;
    
    inline void insert(int x) {
        NumUsed.push_back(x);
    }
    
    void discretize() {
        sort(NumUsed.begin(),NumUsed.end());
        int cur = 0;
        m[NumUsed[0]] = ++cur;
        for (int i = 1; i < NumUsed.size(); i++)
            if (NumUsed[i] != NumUsed[i-1])
                m[NumUsed[i]] = ++cur;
    }
    
    inline int size() {
        return m.size();
    }
    
    inline int operator[] (int x) {
        return m[x];
    }
    
    disc_map(int N) {
        NumUsed.reserve(N);
    }
};
 
struct binary_indexed_tree{
    vector<int> BIT;
    int size = 0;
    
    inline void set(int id, int val) {
        int d = val - query(id,id);
        if (d != 0)
            insert(id,d);
    }
    
    inline void insert(int id, int val) {
        while (id < size) {
            BIT[id] += val;
            id += (id & -id);
        }
    }
    
    inline long long query_from1(int id) {
        long long ans = 0;
        while (id > 0) {
            ans += BIT[id];
            id -= (id & -id);
        }
        return ans;
    }
    
    inline long long query(int l, int r) {
        if (l > r) return 0;
        return query_from1(r) - query_from1(l-1);
    }
    
    binary_indexed_tree(int N) {
        BIT.resize(N+1,0);
        size = N+1;
    }
};
 
pair<int,int> coor[200007];
int cnts[200007];
 
bool cmp(pair<int,int> a, pair<int,int> b) {
	return (a.second < b.second || (a.second == b.second && a.first < b.first));
}
 
int main() {
	int n;
	cin >> n;
	
	disc_map dm(200007);
	
	for (int i = 0; i < n; i++) {
		cin >> coor[i].first >> coor[i].second;
		dm.insert(coor[i].first);
	}
	
	dm.discretize();
	for (int i = 0; i < n; i++)	
		coor[i].first = dm[coor[i].first];
		
	sort(coor,coor+n,cmp);
		
	binary_indexed_tree BIT(200007);
	
	long long ans = 0;
		
	for (int i = n-1; i >= 0; i--) {
		int r;
		for (r = i; r > 0 && coor[r].second == coor[r-1].second; r--);
		for (int j = i; j >= r; j--)
			BIT.set(coor[j].first,1);
		for (int j = i; j >= r; j--)
			if (j == r)
				ans += BIT.query(1,coor[j].first)*BIT.query(coor[j].first,BIT.size-1);
			else
				ans += BIT.query(coor[j-1].first+1,coor[j].first)*BIT.query(coor[j].first,BIT.size-1);
		i = r;
	}
	
	cout << ans;
}

static auto _batch_ios = [](){
	ios::sync_with_stdio(false);
	cin.tie(0);
	return 42;
}();
template <class T1, class T2>
ostream& operator << (ostream& out, pair<T1,T2> p) {
	return out << '(' << p.first << ',' << p.second << ')';
}
template <template <class...> class _TContainer, class... _T>
ostream& operator << (ostream& out, _TContainer<_T...>& _Container) {	
    out << '[';
    bool first = 1;
    for(auto x : _Container) {
    	if (!first) out << ',';
    	out << x;
    	first = 0;
    }
    out << ']';
    return out;
}