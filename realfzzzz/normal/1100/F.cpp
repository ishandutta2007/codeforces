#include<algorithm>
#include<vector>
#include<cctype>
#include<cstdio>
using namespace std;
inline int readint(){
	int x=0;
	bool f=0;
	char c=getchar();
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
const int maxn=5e5+5;
int n,q,c[maxn],l[maxn];
int p[25],pos[25];
void insert(int x,int k){
	for(int i=24;i>=0;i--) if(k>>i&1){
		if(!p[i]){
			p[i]=k;
			pos[i]=x;
			return;
		}
		else{
			if(x>pos[i]){
				swap(x,pos[i]);
				swap(k,p[i]);
			}
			k^=p[i];
		}
	}
}
vector<int> v[maxn];
int ans[maxn];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	for(int i=1;i<=n;i++) c[i]=readint();
	q=readint();
	for(int i=0;i<q;i++){
		l[i]=readint();
		v[readint()].push_back(i);
	}
	for(int i=1;i<=n;i++){
		insert(i,c[i]);
		for(int j=0;j<(int)v[i].size();j++){
			int res=0;
			for(int k=24;k>=0;k--) if(!(res>>k&1)&&pos[k]>=l[v[i][j]]) res^=p[k];
			ans[v[i][j]]=res;
		}
	}
	for(int i=0;i<q;i++) printf("%d\n",ans[i]);
	return 0;
}