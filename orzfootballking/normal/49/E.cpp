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
int dp[55][55]; 
bool p1[26][55][55],p2[26][55][55];int m;
int maxi=1e9;
char s1[55],s2[55];
char c[55],l[55],r[55];
signed main(){
	scanf("%s",s1+1);
	int l1=strlen(s1+1);
	scanf("%s",s2+1);
	int l2=strlen(s2+1);
	scanf("%d",&m);
	char s[6];
	FOR(i,1,m){
		scanf("%s",s+1);
		c[i]=s[1];
		l[i]=s[4];
		r[i]=s[5];
	}
	FOR(i,1,l1){
		p1[s1[i]-'a'][i][i]=1;
	}
	rep(i,1,l1){
		FOR(tl,1,l1-i){
			int tr=tl+i;
			rep(tm,tl,tr){
				FOR(use,1,m){
					if(p1[l[use]-'a'][tl][tm]&&p1[r[use]-'a'][tm+1][tr]){
						p1[c[use]-'a'][tl][tr]=1;
					} 
				}
			}
		}
	}
	FOR(i,1,l2){
		p2[s2[i]-'a'][i][i]=1;
	}
	rep(i,1,l2){
		FOR(tl,1,l2-i){
			int tr=tl+i;
			rep(tm,tl,tr){
				FOR(use,1,m){
					if(p2[l[use]-'a'][tl][tm]&&p2[r[use]-'a'][tm+1][tr]){
						p2[c[use]-'a'][tl][tr]=1;
					} 
				}
			}
		}
	}
	FOR(i,0,l1)FOR(j,0,l2)dp[i][j]=maxi;
	FOR(i,0,l1){
		FOR(j,0,l2){
			if(!i&&!j){
				dp[i][j]=0;continue;
			}
			rep(i1,0,i){
				rep(j1,0,j){
					if(dp[i1][j1]==maxi)continue;
					FOR(use,0,25){
						if(p1[use][i1+1][i]&&p2[use][j1+1][j]){
							gmin(dp[i][j],dp[i1][j1]+1);break;
						}
					}
				}
			}
		}
	}
	if(dp[l1][l2]!=maxi){
		cout<<dp[l1][l2];
	}else cout<<-1;
	RE 0;
}