#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(ut)(b);i++)
#define REP(i,b) FOR(i,0,b)
#define PB push_back
#define ALL(c) c.begin(),c.end()
#define int long long
using namespace std;
typedef long long LL;
typedef LL ut;
typedef pair<ut,ut> pr;
typedef vector<pr> Vpr;
typedef priority_queue<pr,Vpr,greater<pr> > PQ;
const int SIZE=2*1e5;
LL a[SIZE],b[SIZE],p[SIZE],BIT[SIZE],tar[SIZE];
Vpr ps,bs;
void add(int x,int val){
	x++;
	while(x<=SIZE){
		BIT[x]+=val;
		x+=x&-x;
	}
}
LL sum(int x){
	x++;
	if(x==0) return 0;
	LL ans=0;
	while(x>0){
		ans+=BIT[x];
		x-=x&-x;
	}
	return ans;
}
LL sum(int a,int b){
	return sum(b)-sum(a-1);
}
LL sear(int e){
	int s=0;
	while(s<=e){
		int f=(s+e)/2;
		if(sum(f,e)){
			s=f+1;
		}else{
			e=f-1;
		}
	}	
	return e;
}
signed main(){
	int n,m;
	cin >> n >> m;
	REP(i,n){
		cin >> a[i];
		add(i,a[i]);
	}
	REP(i,m){
		cin >> b[i];
		bs.PB(pr(b[i],i));
	}
	REP(i,m){
		cin >> p[i];
		ps.PB(pr(p[i],i));
	}
	sort(ALL(ps));
	sort(ALL(bs));
	int nows=0;
	REP(i,SIZE) tar[i]=-1;
	REP(i,n){
		int now=n-i-1;
		while(nows!=ps.size() && bs[nows].first<=a[now]){
			tar[bs[nows].second]=now;
			nows++;
		}
	}
	int ans=0;
	REP(i,m){
		LL needs=ps[i].first;
		LL target=tar[ps[i].second];
		//cout << ps[i].second << " " <<target << endl;
		
		if(sum(0,target)>=needs){
			ans++;
			while(needs>0){
				int next=sear(target);
				LL duce=sum(next,next);
				add(next,-min(needs,duce));
				needs-=min(needs,duce);
			}
		}
	//	cout << sum(0,n) << endl;
	}
	cout << ans << endl;
	return 0;
}