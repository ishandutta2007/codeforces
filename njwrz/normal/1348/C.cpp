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
int cnt[30];
void solve(){
	int n,k;
	FILL(cnt,0);
	string s;
	cin>>n>>k>>s;
	for(auto u:s)cnt[u-'a']++;
	bool f=1;
	rep(i,0,26){
		if(cnt[i]){
			if(cnt[i]>=k){
				if(f){
					if(cnt[i]==k){
						cout<<(char)(i+'a');
						int count=0,tmp;
						rep(j,i+1,26){
							if(cnt[j]>0){
								count++;
								tmp=j;
							}
						}
						if(count==1){
							FOR(j,1,cnt[tmp]/k+(cnt[tmp]%k!=0))cout<<(char)(tmp+'a');
						}else{
							rep(j,i+1,26){
								FOR(p,1,cnt[j])cout<<(char)(j+'a');
							}
						}
						cout<<'\n';
						RE;
					}
					int count=0;
					rep(j,i+1,26){
						if(cnt[j]>0){
							count++;
						}
					}
					if(!count){
						FOR(j,1,cnt[i]/k+(cnt[i]%k!=0))cout<<(char)(i+'a');
						cout<<'\n';
						RE;
					}
					FOR(j,0,cnt[i]-k)cout<<(char)(i+'a');
					rep(j,i+1,26){
						FOR(p,1,cnt[j])cout<<(char)(j+'a');
					}
					cout<<'\n';
				}else{
					cout<<(char)(i+'a')<<'\n';
				}
				RE;
			}
			f=0;k-=cnt[i];
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}