#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
const int inf=1e9+7;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

char a[N];
int sum[N*15][10],now[10],cnt=0;
vector<pair<int,int>>ri[N];
vector<int>t[N];
int L[N],R[N],le[N],p[N];
void del(int x)
{
	L[R[x]]=L[x];
	R[L[x]]=R[x];
	ri[L[x]].push_back(make_pair(cnt+1,R[x]));
}
int getnext(int x,int f){return f>0?R[x]:L[x];}
void albcwt(int n)
{
	for (int i=1;i<=n+1;i++) L[i]=i-1;
	for (int i=0;i<=n;i++) R[i]=i+1;
	for (int i=1;i<=n;i++) ri[i].push_back(make_pair(0,i+1));
	while (1)
	{
		int pos=R[0],f=1;
		if (pos>n) break;
		stack<int>st;
		while (1<=pos&&pos<=n)
		{
//			cerr<<pos<<' '<<a[pos]<<' '<<(st.empty()?0:st.top())<<' '<<R[pos]<<endl;
			if (isdigit(a[pos])) now[a[pos]-'0']++;
			memcpy(sum[++cnt],now,sizeof(now));
			if (t[pos].empty()) p[pos]=st.empty()?0:st.top(),le[pos]=L[pos];
			t[pos].push_back(cnt);
			if (isdigit(a[pos]))
			{
				int nxt=getnext(pos,f);
				if (a[pos]>'0') a[pos]--;
						   else del(pos);
				pos=nxt;
			}
			else if (a[pos]=='>'||a[pos]=='<')
			{
				f=a[pos]=='>'?1:-1;
				int nxt=getnext(pos,f);
				if (!isdigit(a[nxt])) del(pos);
				pos=nxt;
			}
			else if (a[pos]=='[')
			{
				if (st.empty()||st.top()<pos) st.push(pos);
				int nxt=getnext(pos,f);
				if (a[nxt]=='['||a[nxt]==']'||nxt>n) del(pos),st.pop();
				else if (nxt<pos) st.pop();
				pos=nxt;
			}
			else if (a[pos]==']')
			{
				if (st.empty()){del(pos),pos=0;break;}
				int nxt=st.top(); st.pop();
				if (nxt==L[pos]) del(pos);
				pos=nxt;
			}
		}
		memcpy(sum[++cnt],now,sizeof(now));
		t[pos].push_back(cnt);
//		cerr<<pos<<endl<<endl;
	}
	t[0].push_back(cnt+1);
	t[n+1].push_back(cnt+1);
}

signed main()
{
	int n=read(),Q=read();
	scanf("%s",a+1);
	albcwt(n);
	while (Q--)
	{
		int l=read(),r=read(),T=t[l][0];
		int lp=le[l];
		int rp=(upper_bound(ri[r].begin(),ri[r].end(),make_pair(T,inf))-1)->second;
		int tl=*lower_bound(t[lp].begin(),t[lp].end(),T);
		int tr=*lower_bound(t[rp].begin(),t[rp].end(),T);
		int ti=min({tl,tr,*lower_bound(t[p[l]].begin(),t[p[l]].end(),T)});
//		cerr<<l<<','<<r<<':'<<lp<<' '<<rp<<endl;
		for (int i=0;i<=9;i++) print(sum[ti-1][i]-sum[T-1][i]," \n"[i==9]);
	}
	
	return 0;
}