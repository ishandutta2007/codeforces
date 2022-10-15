//https://codeforces.com/contest/403/problem/E?fbclid=IwAR18vWBSjnvrDTeACoY5RyUGdjWI1q2e-PMjwyfIKM9wUX5hKH7ohmkvRSg
/*
Tom tat: Cho n diem va 2 tap canh xanh va do, moi tap canh tao thanh 1 cay.
Canh (x,y) khong tuong thich voi (p,q)
neu:
mau(x,y)!=mau(p,q) va
dung 1 dinh x hoac y thuoc cay con cua p va q co cung mau voi (p,q)
O buoc 0 ta xoa 1 canh xanh.
Goi tap canh bi xoa o buoc k la Ak.
Ai=tap cac canh chua xoa ko tuong thich voi it nhat 1 canh trong Ai-1
In ra Ai o moi buoc i.
Loi giai: Viet bang english vi ko du thoi gian
First, for each vertex of the first and second tree we calculate two values in[s], out[s]  the entry time and exit time in dfs order from vertex with number 1. 
Also with each edge from both trees we will assosiate a pair (p,q), where p=min(in[u],in[v]), q=max(in[u],in[v]) (values in,out for each vertex we take from tree with another color). 
Now for each tree we will build two segment trees (yes, totally 4 segment trees). 
In first segment will store all pairs in following way: 
we will store a pair in node of segment tree if and only if  left element of pair lies in segment (l,r). 
In second segment tree we will store a pair if and only if right element of the pair lies in segment (l,r) .
All pairs in segment trees we will store in some order (in first segment tree  increasing order of right element, in the second tree  decreasing order of left element). 
Such trees use O(n log n) of memory, also you can build it in O(n log n).

Good. How to answer on query (l,r)  erase all edges from tree for which exactly one vertex have value in[s] in segment (l,r)? 
We will go down in our segment tree. 
Let's imagine, that now we in some node of segment tree.
Because we store all pairs in the first segment tree in increasing order of the right element, so answer to the query is some suffix of the array of pairs (binary search it). 
After we can add them to the answer (if it not erased yet). 
After that we should modify our segment tree: for each node, where we work with suffixes, we should erase all pairs from such suffix. So, this solution runs in O(n log n). 
*/
#include <bits/stdc++.h>
using namespace std;
 
typedef long long li;
typedef long double ld;
typedef pair<int,int> pt;
typedef pair<ld, ld> ptd;
typedef unsigned long long uli;
 
#define pb push_back
#define mp make_pair
#define mset(a, val) memset(a, val, sizeof (a))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ft first
#define sc second
#define sz(a) int((a).size())
#define x first
#define y second
 
template<typename X> inline X abs(const X& a) { return (a < 0 ? -a : a); }
template<typename X> inline X sqr(const X& a) { return (a * a); }
template<typename T> inline string toStr(T x) { stringstream st; st << x; string s; st >> s; return s; }
template<typename T> inline int hasBit(T mask, int b) { return (b >= 0 && (mask & (T(1) << b)) != 0) ? 1 : 0; }
template<typename X, typename T>inline ostream& operator<< (ostream& out, const pair<T, X>& p) { return out << '(' << p.ft << ", " << p.sc << ')'; }
 
inline int nextInt() { int x; if (scanf("%d", &x) != 1) throw; return x; }
inline li nextInt64() { li x; if (scanf("%I64d", &x) != 1) throw; return x; }
inline double nextDouble() { double x; if (scanf("%lf", &x) != 1) throw; return x; }
 
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, a, b) for(int i = int(a); i <= int(b); i++)
#define ford(i, n) for(int i = int(n - 1); i >= 0; i--)
#define foreach(it, a) for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
 
 
const int INF = int(1e9);
const li INF64 = li(INF) * li(INF);
const ld EPS = 1e-9;
const ld PI = ld(3.1415926535897932384626433832795);
 
const int N = 2 * 1000 * 100 + 10;
 
int n;
 
pt edges[2][N];            
int in[2][N], out[2][N], cur[N], szcur, curtime, szncur, ncur[N];
int used[2][N];
 
vector < int > g[2][N];
 
vector < pt > tv1[2][2 * N], tv2[2][2 * N];
vector < pt > t[4][8 * N];
 
inline bool read() 
{
    n = nextInt();
   	forn(it, 2)
   	{
   	 	forn(i, n - 1)
   	 	{
   	 	 	int a = nextInt() - 1;
   	 	 	int b = i + 1; 
   	 	 	edges[it][i] = mp(a, b);
        	g[it][a].pb(b);
     	 	g[it][b].pb(a);
        }
   	}
 
	int i = nextInt() - 1;
 
  	cur[szcur ++] = i;
  	
  	return true;
}
 
void go(int id, int s, int prev = -1)
{
 	in[id][s] = curtime++;
 
 	forn(i, sz(g[id][s])) 
 	{
 		int to = g[id][s][i];
 
 	 	if (to == prev) continue;
 
 	 	go(id, to, s); 	
 	}                   	
 	out[id][s] = curtime ++;
}
 
void buildByFt(int v, int tl, int tr, int id)
{
 	if (tl == tr) 
 	{
 		t[id][v] = tv1[id][tl];
 		sort(all(t[id][v]));
 		return;
 	}
 
	int mid = (tl + tr) >> 1;
	buildByFt((v << 1), tl, mid, id);
	buildByFt((v << 1) + 1, mid + 1, tr, id);
	
	int i = 0;
	int j = 0;
	
	int szt = 0;
 
	int szt1 = sz(t[id][(v << 1)]);
	int szt2 = sz(t[id][(v << 1) + 1]);
 
	int allszt = sz(t[id][(v << 1)]) + sz(t[id][(v << 1) + 1]);
	
	t[id][v].resize(allszt);
 
	while (szt < allszt)
	{
	 	if (i < szt1 && j < szt2)
	 	{
	 	 	if (t[id][(v << 1)][i] <= t[id][(v << 1) + 1][j])
	 	 	{
	 	 		t[id][v][szt++] = t[id][(v << 1)][i];
	 	 		i++;
	 	 	}
	 	 	else
	 	 	{
	 	 		t[id][v][szt++] = t[id][(v << 1) + 1][j];
	 	 		j++;
	 	 	}
	 	 	continue;
	 	}
	 	if (i < szt1)
	 	{
	 		t[id][v][szt++] = t[id][(v << 1)][i];
	 	 	i++;
	 	}
 
	 	if (j < szt2)
	 	{
	 	 	t[id][v][szt++] = t[id][(v << 1) + 1][j];
	 	 	j++;
	 	}
	}
}
 
void buildBySc(int v, int tl, int tr, int id)
{
 	if (tl == tr) 
 	{
 	    t[id + 2][v] = tv2[id][tl];
        sort(all(t[id + 2][v]));
        reverse(all(t[id + 2][v]));
    
        return;
 	}
 
    int mid = (tl + tr) >> 1;
	buildBySc((v << 1), tl, mid, id);
	buildBySc((v << 1) + 1, mid + 1, tr, id);
	
	id += 2;
 
	int i = 0;
	int j = 0;
	
	int szt = 0;
 
	int szt1 = sz(t[id][(v << 1)]);
	int szt2 = sz(t[id][(v << 1) + 1]);
 
	int allszt = sz(t[id][(v << 1)]) + sz(t[id][(v << 1) + 1]);
	
	t[id][v].resize(allszt);
 
	while (szt < allszt)
	{
	 	if (i < szt1 && j < szt2)
	 	{
	 	 	if (t[id][(v << 1)][i] >= t[id][(v << 1) + 1][j])
	 	 	{
	 	 		t[id][v][szt++] = t[id][(v << 1)][i];
	 	 		i++;
	 	 	}
	 	 	else
	 	 	{
	 	 		t[id][v][szt++] = t[id][(v << 1) + 1][j];
	 	 		j++;
	 	 	}
	 	 	continue;
	 	}
	 	if (i < szt1)
	 	{
	 		t[id][v][szt++] = t[id][(v << 1)][i];
	 	 	i++;
	 	}
 
	 	if (j < szt2)
	 	{
	 	 	t[id][v][szt++] = t[id][(v << 1) + 1][j];
	 	 	j++;
	 	}
	}
}
 
void get(int v, int tl, int tr, int l, int r, int id, int tvalue)
{
 	if (l > r)
 		return;                                     
                       
 
 	if (l == tl && r == tr)
 	{
 		
 		if (id < 2)
 		{
 			while (!t[id][v].empty())
 			{
 			 	pt s = t[id][v].back();
 
 			 	if (s.ft > tvalue)
 			 	{                        
 			 		
 			 		if (!used[id & 1][s.sc]) 
 			 	    {
 			 	    	used[id & 1][s.sc] = 1;
 			 	    	ncur[szncur++] = s.sc;
 			 	    }
 
 			 	    t[id][v].pop_back();
 			 	} else
 			 		break;	
 			}
 		} 
 		else
 		{
 			while (!t[id][v].empty())
 			{
 			 	pt s = t[id][v].back();
 			 	if (s.ft < tvalue) 
               	{                
 			 	    if (!used[id & 1][s.sc])
 			 	    {
 			 	    	used[id & 1][s.sc] = 1;
 			 	    	ncur[szncur++] = s.sc;
 			 	    }
 			 	    t[id][v].pop_back();
 			 	} else
 			 		break;	
 			}
 		}
 
 	   	return;
	}
 
	int mid = (tl + tr) >> 1;
 
	get((v << 1), tl, mid, l, min(r, mid), id, tvalue);
	get((v << 1) + 1, mid + 1, tr, max(l, mid + 1), r, id, tvalue);
		
} 
inline void solve() 
{       
    curtime = 0;
    go(0, 0);
 
    curtime = 0;
    go(1, 0);    
 
    forn(it, 2)
	 	forn(i, n - 1)
	 	{
	 		int u = edges[it][i].ft;
	 		int v = edges[it][i].sc;
       
         	int dv1 = in[it ^ 1][u];
        	int dv2 = in[it ^ 1][v];
 
        	if (dv1 > dv2)
        		swap(dv1, dv2);
 
        	tv1[it][dv1].pb(mp(dv2, i));
        	tv2[it][dv2].pb(mp(dv1, i));
        }
	
	forn(it, 2)
		buildByFt(1, 0, 2 * n - 1, it);
 
	forn(it, 2)
		buildBySc(1, 0, 2 * n - 1, it);
 
    int idx = 0;
 
    forn(i, szcur)
    	used[0][cur[i]] = 1;
 
	while(true)
	{                
		if (szcur == 0) break;
		if (idx & 1)
			puts("Red");
		else
			puts("Blue");
 
		sort(cur, cur + szcur);
 
		forn(i, szcur) 
		{
			if (i) printf(" ");
			printf("%d", cur[i] + 1);
		}		 	
		puts("");
		forn(i, szcur) 
		{
			int u = edges[idx][cur[i]].ft;
			int v = edges[idx][cur[i]].sc;
 
		}
 
		forn(i, szcur) 
		{
			int u = edges[idx][cur[i]].ft;
			int v = edges[idx][cur[i]].sc;
        	
        	int l, r;
 
        	if (out[idx][u] > out[idx][v])
        		l = in[idx][v], r = out[idx][v];
        	else
        		l = in[idx][u], r = out[idx][u];
        
            if (!(idx & 1))
        		get(1, 0, 2 * n - 1, l, r, 1, r),
        		get(1, 0, 2 * n - 1, l, r, 3, l);
       		else
       			get(1, 0, 2 * n - 1, l, r, 0, r),
        		get(1, 0, 2 * n - 1, l, r, 2, l);
       			
        }
  
        idx ^= 1;
 
        forn(i, szncur)
        	cur[i] = ncur[i];
 
        szcur = szncur;
        szncur = 0;
   	}
}
 
int main() 
{
#ifdef gridnevvvit
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif                    
 
	cout << setprecision(10) << fixed;
	cerr << setprecision(5) << fixed;
 
	assert(read());
	solve();
}