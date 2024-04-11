#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define lb(x) ((x)&(-x))
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define de(x) cout<<x<<" x"<<endl
#define LCAFA rep(i,1,20)rep(j,1,n+1)fa[j][i]=fa[fa[j][i-1]][i-1]
#define all(x) x.begin(),x.end()
using namespace std;
const int N=2e6+9;
const ll mod=998244353;
int vis[26];
char s[N],t[N];
int main(){
	scanf("%s",s);
	int len=strlen(s);
	rep(i,0,len)vis[s[i]-'a']=1;
	scanf("%s",s);
	len=strlen(s);
	int pos=len;
	rep(i,0,len)if(s[i]=='*'){
		pos=i;
		break;
	}
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%s",t);
		int lent=strlen(t);
		if(pos<len){
			if(lent+1<len){
				printf("NO\n");
				continue;
			}
			int flag=1;
			rep(i,0,pos){
				if(s[i]!=t[i]){
					if(s[i]!='?'||!vis[t[i]-'a']){
						flag=0;
						break;	
					}
				}
			}
			per(i,pos+1,len){
				if(s[i]!=t[lent-(len-i)]){
					if(s[i]!='?'||!vis[t[lent-len+i]-'a']){
						flag=0;
						break;
					} 
				}
			}
			rep(i,pos,lent-len+pos+1){
				if(vis[t[i]-'a']){
					flag=0;
					break;
				}
			}
			if(flag)printf("YES\n");
			else printf("NO\n");
		}
		else{
			if(len!=lent){
				printf("NO\n");
				continue;
			}
			int flag=1;
			rep(i,0,len){
				if(s[i]!=t[i]){
					if(s[i]!='?'||!vis[t[i]-'a']){
						flag=0;
						break;	
					}
				}
			}
			if(flag)printf("YES\n");
			else printf("NO\n");
		}
	}
}