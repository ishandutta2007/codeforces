#include <bits/stdc++.h>

namespace IO
{
char gc()
{
#ifdef FREAD
	static char buf[1<<21], *P1 = buf, *P2 = buf;
	if(P1 == P2)
	{
		P1 = buf;
		P2 = buf + fread(buf, 1, 1<<21, stdin);
		if(P1 == P2) return EOF;
	}
	return *(P1++);
#else
	return getchar();
#endif
}
template<typename Tp> bool get1(Tp &x)
{
	bool neg = 0;
	char c = gc();
	while( c != EOF && (c < '0' || c > '9') && c != '-' ) c = gc();
	if(c == '-') c = gc(), neg = 1;
	if(c == EOF) return false;
	x = 0;
	for(; c>='0' && c<='9'; c = gc()) x = x*10 + c - '0';
	if(neg) x = -x;
	return true;
}
template<typename Tp> void printendl(Tp x)
{
	if(x<0)putchar('-'),x=-x;
	static short a[40], sz;
	sz = 0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1; i>=0; i--)putchar('0'+a[i]);
	puts("");
}
} // namespace IO
using IO::get1;
using IO::printendl;
#define get2(x,y) get1(x) && get1(y)
#define get3(x,y,z) get2(x,y) && get1(z)
#define get4(x,y,z,w) get3(x,y,z) && get1(w)
#define pb push_back
#define mp std::make_pair
#define ff first
#define ss second
typedef long long LL;
typedef unsigned long long uLL;
typedef std::pair<int,int> pii;
const int inf = 0x3f3f3f3f;
const LL Linf = 1ll<<61;

const int maxn = 200111;

char s[maxn];
int n, cnt[26], sum;

int bit[maxn]; std::set<int> st;
void add(int x, int v) { for(; x<maxn; x+=x&-x) bit[x] += v; }
int query(int x) { int ret = 0; for(; x; x-=x&-x) ret += bit[x]; return ret; }
std::vector<pii> ansv;
void clear_all(int l, int r)
{
	ansv.emplace_back(query(l-1)+1, query(r));
	std::vector<int> vs;
	for(auto it = st.lower_bound(l); it != st.end() && (*it) <= r; it++) vs.pb(*it);
	for(auto v : vs)
	{
		add(v, -1);
		st.erase(v);
	}
}

pii stk[maxn]; int top;
void solve(int tc)
{
	scanf("%s", s+1);
	n = strlen(s+1);
	
	ansv.clear();
	for(int i=1; i<=n; i++)
	{
		st.insert(i);
		add(i, 1);
	}
	
	memset(cnt, 0, sizeof(cnt)); sum = 0;
	std::queue<pii> qq;
	for(int i=1; i<=n; i++) if(s[i] == s[i-1])
	{
		cnt[s[i]-'a']++;
		qq.emplace(i-1, s[i]-'a');
		sum++;
	}
	
	int maxv = 0; for(int i=0; i<26; i++) if(cnt[i] > cnt[maxv]) maxv = i;
	top = 0;
	while(!qq.empty() && cnt[maxv] * 2 < sum)
	{
		auto q = qq.front(); qq.pop();
		if(top == 0 || stk[top].ss == q.ss) stk[++top] = q;
		else
		{
			clear_all(stk[top].ff+1, q.ff);
			cnt[stk[top].ss]--;
			cnt[q.ss]--;
			sum -= 2;
			maxv = 0; for(int i=0; i<26; i++) if(cnt[i] > cnt[maxv]) maxv = i;
			top--;
		}
	}
	while(!qq.empty())
	{
		auto q = qq.front(); qq.pop();
		if(top && stk[top].ss != q.ss && (stk[top].ss == maxv || q.ss == maxv))
		{
			clear_all(stk[top].ff+1, q.ff);
			cnt[stk[top].ss]--;
			cnt[q.ss]--;
			sum -= 2;
			top--;
		}
		else stk[++top] = q;
	}
	int now = 1;
	for(int i=1; i<=top; i++)
	{
		clear_all(now, stk[i].ff);
		now = stk[i].ff+1;
	}
	clear_all(now, n);
	printf("%d\n", (int)ansv.size());
	for(auto v : ansv) printf("%d %d\n", v.ff, v.ss);
}

int main()
{
	int tc;
	get1(tc);
	for(int i=1; i<=tc; i++) solve(i);
	return 0;
}