#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(int i=(a);i>=(b);--i)
//#define int long long 
using namespace std;
inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

#define fi first
#define se second
#define pb push_back
#define mkp make_pair
typedef pair<int,int>pii;
typedef vector<int>vi;
  
#define maxn 400005
#define inf 0x3f3f3f3f

bool vis[233];
vi o[233];
void work()
{
	string s,t;
	cin>>s>>t;
	int n=s.size(),m=t.size();
	For(i,0,n)vis[i]=0;
	For(i,0,25)o[i].clear();
	For(i,0,n-1)o[s[i]-'A'].pb(i);
	For(i,0,m-1){
		int c=t[i]-'A';
		if(!o[c].size()){
			puts("NO");
			return;
		}
		vis[o[c].back()]=1;
		o[c].pop_back();
	}
	string res="";
	For(i,0,n-1)
		if(vis[i]) res+=s[i];
	if(res==t)puts("YES");
	else puts("NO");
}

signed main()
{
	int T=read();
	while(T--)work();
	return 0;
}