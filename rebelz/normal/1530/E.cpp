#include<bits/stdc++.h>

#define y1 dmytxdy
#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
int cnt[26];
char s[100005];

int main(){
	int T=readint();
	while(T--){
		scanf("%s",s+1);
		n=strlen(s+1);
		if(n==1){
			puts(s+1);
			continue;
		}
		for(int i=0;i<26;i++) cnt[i]=0;
		for(int i=1;i<=n;i++) cnt[s[i]-'a']++;
		int hv=-1;
		for(int i=0;i<26;i++){
			if(cnt[i]==1){
				hv=i;
				break;
			}
		}
		if(hv>=0){
			cnt[hv]--;
			putchar('a'+hv);
			for(int i=0;i<26;i++) for(int j=1;j<=cnt[i];j++) putchar('a'+i);
			putchar('\n');
			continue;
		}
		int pl=0;
		for(int i=0;i<26;i++){
			if(cnt[i]){
				pl=i;
				break;
			}
		}
		if(cnt[pl]>1&&cnt[pl]-2<=(n-2)/2){
			putchar('a'+pl);
			putchar('a'+pl);
			cnt[pl]-=2;
			bool fl=1;
			for(int i=3;i<=n;i++){
				for(int j=pl+fl;j<26;j++){
					if(cnt[j]){
						cnt[j]--;
						putchar('a'+j);
						fl=(j==pl);
						break;
					}
				}
			}
			putchar('\n');
			continue;
		}
		if(cnt[pl]==1){
			for(int i=0;i<26;i++) for(int j=1;j<=cnt[i];j++) putchar('a'+i);
			putchar('\n');
			continue;
		}
		putchar('a'+pl);
		cnt[pl]--;
		int cho=-1;
		for(int i=pl+1;i<26;i++){
			if(cnt[i]){
				cnt[i]--;
				putchar('a'+i);
				cho=i;
				break;
			}
		}
		if(cho<0){
			for(int i=2;i<=n;i++) putchar('a'+pl);
			putchar('\n');
			continue;
		}
		if(cnt[pl]+cnt[cho]==n-2){
			for(int i=1;i<=cnt[cho];i++) putchar('a'+cho);
			for(int i=1;i<=cnt[pl];i++) putchar('a'+pl);
			putchar('\n');
			continue;
		}
		for(int i=1;i<=cnt[pl];i++) putchar('a'+pl);
		for(int i=cho+1;i<26;i++){
			if(cnt[i]){
				cnt[i]--;
				putchar('a'+i);
				break;
			}
		}
		for(int i=cho;i<26;i++) for(int j=1;j<=cnt[i];j++) putchar('a'+i);
		putchar('\n');
	}
	return 0;
}