#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define per(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define ll long long
#define pii pair<int,int>
using namespace std;
const int N=60;
char s[N],t[N];
int tot[30],cnt[30];
pii ans[N<<1];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		scanf("%s",s);
		scanf("%s",t);
		memset(tot,0,sizeof tot);
		rep(i,0,n){
			tot[s[i]-'a']++;
			tot[t[i]-'a']++;
		}
		int flag=0;
		rep(i,0,26){
			if(tot[i]&1){
				flag=1;
				break;
			}
		}
		if(flag){
			printf("No\n");
			continue;
		}
		printf("Yes\n");
		int summ=0;
		rep(i,0,n){
			if(s[i]!=t[i]){
				int ok=0,p;
				rep(j,i+1,n){
					if(s[j]==s[i]){
						p=j;
						ok=1;
						break;
					}
				}
				if(ok){
					ans[summ++]={p+1,i+1};
					swap(t[i],s[p]);
					continue;
				}
				rep(j,i+1,n){
					if(t[j]==s[i]){
						p=j;
						break;
					}
				}
				ans[summ++]={i+2,p+1};
				ans[summ++]={i+2,i+1}; 
				swap(t[p],s[i+1]);
				swap(t[i],s[i+1]);
			}
		}
		printf("%d\n",summ);
		rep(i,0,summ)printf("%d %d\n",ans[i].first,ans[i].second);
	}
}