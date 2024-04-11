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
int cnt[30];
void solve(){
	FILL(cnt,0);
	int n;
	string ts;
	cin>>ts;
	n=ts.size();
	FOR(i,1,n){
		char c=ts[i-1];
		cnt[c-'a']++;
	}
	int fir=0;
	rep(i,0,26)if(cnt[i]){
		fir=i;break;
	}
	if(cnt[fir]==n){
		FOR(i,1,n)cout<<((char)(fir+'a'));
		RE ;
	}
	rep(i,0,26){
		if(cnt[i]==1){
			cout<<((char)(i+'a'));cnt[i]--;
			FOR(j,0,25){
				FOR(k,1,cnt[j])cout<<((char)(j+'a'));
			}
			RE;
		}
	}
	if(cnt[fir]>1&&n-cnt[fir]>=cnt[fir]-2){
		int tl=fir+1;
		cnt[fir]-=2;
		cout<<((char)(fir+'a'))<<((char)(fir+'a'));
		FOR(i,1,n-2){
			if((i&1)||!cnt[fir]){
				while(!cnt[tl])tl++;
				cnt[tl]--;
				cout<<((char)(tl+'a'));
			}else cout<<((char)(fir+'a')),cnt[fir]--;
		}
		RE ;
	}
	int sec;
	rep(i,fir+1,26){
		if(cnt[i]){
			sec=i;break;
		}
	}
	if(cnt[fir]+cnt[sec]==n||cnt[fir]==1){
		cout<<((char)(fir+'a'));
		FOR(i,1,cnt[sec]){
			cout<<((char)(sec+'a'));
		}
		rep(i,1,cnt[fir])cout<<((char)(fir+'a'));
		FOR(i,sec+1,25){
			FOR(j,1,cnt[i])cout<<((char)(i+'a'));
		}
	}else{
		cout<<((char)(fir+'a'));
		cout<<((char)(sec+'a'));
		rep(i,1,cnt[fir]){
			cout<<((char)(fir+'a'));
		}
		rep(i,sec+1,26)if(cnt[i]){
			cnt[i]--;
			cout<<((char)(i+'a'));
			break;
		}
		rep(i,1,cnt[sec]){
			cout<<((char)(sec+'a'));
		}
		FOR(i,sec+1,25){
			FOR(j,1,cnt[i])cout<<((char)(i+'a'));
		}
	}
	RE ;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve(),cout<<'\n';
	RE 0;
}