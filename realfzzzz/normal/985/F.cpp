#include<algorithm>
#include<vector>
#include<cstdio>
#include<cctype>
using namespace std;
inline int readint(){
	int x=0;
	char c=getchar();
	bool f=0;
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-'){
		f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=2e5+5;
int n,m;
char s[maxn];
typedef long long ll;
const ll mod1=998244353,mod2=1e9+7,p=173;
ll hs1[26][maxn],pw1[maxn],hs2[26][maxn],pw2[maxn];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	m=readint();
	scanf("%s",s+1);
	for(int i=0;i<26;i++) for(int j=1;j<=n;j++)
		hs1[i][j]=(hs1[i][j-1]*p%mod1+(s[j]-'a'==i))%mod1;
	for(int i=0;i<26;i++) for(int j=1;j<=n;j++)
		hs2[i][j]=(hs2[i][j-1]*p%mod2+(s[j]-'a'==i))%mod2;
	pw1[0]=1;
	for(int i=1;i<=n;i++) pw1[i]=pw1[i-1]*p%mod1;
	pw2[0]=1;
	for(int i=1;i<=n;i++) pw2[i]=pw2[i-1]*p%mod2;
	while(m--){
		int x,y,len;
		x=readint();
		y=readint();
		len=readint();
		vector<int> res1,res2;
		for(int i=0;i<26;i++){
			res1.push_back((hs1[i][x+len-1]-hs1[i][x-1]*pw1[len]%mod1+mod1)%mod1);
			res2.push_back((hs1[i][y+len-1]-hs1[i][y-1]*pw1[len]%mod1+mod1)%mod1);
		}
		sort(res1.begin(),res1.end());
		sort(res2.begin(),res2.end());
		if(res1!=res2){
			printf("NO\n");
			continue;
		}
		vector<int>().swap(res1);
		vector<int>().swap(res2);
		for(int i=0;i<26;i++){
			res1.push_back((hs2[i][x+len-1]-hs2[i][x-1]*pw2[len]%mod2+mod2)%mod2);
			res2.push_back((hs2[i][y+len-1]-hs2[i][y-1]*pw2[len]%mod2+mod2)%mod2);
		}
		sort(res1.begin(),res1.end());
		sort(res2.begin(),res2.end());
		if(res1!=res2){
			printf("NO\n");
			continue;
		}
		printf("YES\n");
	}
	return 0;
}