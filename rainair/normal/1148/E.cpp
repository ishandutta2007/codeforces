#include <bits/stdc++.h>

#define fi first
#define se second
#define db double
#define U unsigned
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 3e5 + 5;
P s[MAXN];
int t[MAXN],n;

int main(){
	scanf("%d",&n);
	FOR(i,1,n) scanf("%d",&s[i].fi),s[i].se = i;
	FOR(i,1,n) scanf("%d",t+i);
	std::sort(s+1,s+n+1);std::reverse(s+1,s+n+1);
	std::sort(t+1,t+n+1);std::reverse(t+1,t+n+1);
	std::priority_queue<P> q;
	std::vector<std::pair<P,int> > ans;
	FOR(i,1,n){
		if(s[i].fi == t[i]) continue;
		if(s[i].fi > t[i]){
			q.push(MP(s[i].fi-t[i],s[i].se));
			s[i].fi = t[i];
		}
		else{
			int d = t[i]-s[i].fi;
			while(!q.empty() && d){
				P v = q.top();q.pop();
				if(d >= v.fi){
					d -= v.fi;
					ans.pb(MP(MP(s[i].se,v.se),v.fi));
				}
				else{
					q.push(MP(v.fi-d,v.se));
					ans.pb(MP(MP(s[i].se,v.se),d));
					d = 0;
				}
			}
			if(d){
				puts("NO");return 0;
			}
		}
	}
	while(!q.empty() && q.top().fi == 0) q.pop();
	if(!q.empty()){
		puts("NO");
		return 0;
	}
	puts("YES");
	printf("%d\n",(int)ans.size());
	for(auto x:ans) printf("%d %d %d\n",x.fi.fi,x.fi.se,x.se);
	return 0;
}