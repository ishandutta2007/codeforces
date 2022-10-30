#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
int cnt[10],t1[10],t2[10]; 
string s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>s;
	rep(i,0,s.size())cnt[s[i]-'0']++;
	int ans=-1e8,anst=-1,t,now;
	FOR(i,1,9){
		FOR(j,0,9)t1[j]=t2[j]=cnt[j];
		if(!t1[i]||!t2[10-i])continue;
		t1[i]--;
		t2[10-i]--;
		t=0;
		FOR(j,0,9){
			now=min(t1[j],t2[9-j]);
			t+=now;t1[j]-=now;t2[9-j]-=now;
		}
//		cout<<t<<' ';
		t+=min(t1[0],t2[0]);
//		cout<<t<<'\n';
		if(ans<t){
			ans=t;
			anst=i;
		}
	} 
	deque<int> ans1,ans2;
	if(anst==-1){
		FOR(i,0,9){
			FOR(j,1,cnt[i]){
				ans1.PB(i);
				ans2.PB(i);
			}
		}
	}else{
	ans1.PB(anst);ans2.PB(10-anst);
	FOR(i,0,9)t1[i]=t2[i]=cnt[i];
	t1[anst]--;
	t2[10-anst]--;
	FOR(i,0,9){
		t=min(t1[i],t2[9-i]);
		FOR(j,1,t){
			ans1.PB(i);
			ans2.PB(9-i);
		}
		t1[i]-=t;t2[9-i]-=t;
	}
	t=min(t1[0],t2[0]);
	FOR(i,1,t){
		ans1.PF(0);ans2.PF(0);
	}
	t1[0]-=t;t2[0]-=t;
	FOR(i,0,9){
		FOR(j,1,t1[i])ans1.PB(i);
		FOR(j,1,t2[i])ans2.PB(i); 
	}
	}
	reverse(ALL(ans1));
	reverse(ALL(ans2));
	for(auto u:ans1)cout<<u;
	cout<<'\n';
	for(auto u:ans2)cout<<u;
	RE 0;
}