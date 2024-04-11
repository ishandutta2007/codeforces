#include<bits/stdc++.h>
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
const int maxn=1e3+5;
int n,a[maxn*2];
typedef pair<int,int> pii;
vector<pii> solve(multiset<int> s,int x){
	vector<pii> res;
	for(int i=0;i<n-1;i++){
		int u=*--s.end();
		s.erase(s.find(u));
		if(s.find(x-u)==s.end()) return vector<pii>();
		res.push_back(pii(u,x-u));
		s.erase(s.find(x-u));
		x=u;
	}
	return res;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int T=readint();
	while(T--){
		n=readint();
		for(int i=0;i<n*2;i++) a[i]=readint();
		if(n==1){
			printf("YES\n%d\n%d %d\n",a[0]+a[1],a[0],a[1]);
			continue;
		}
		sort(a,a+n*2);
		multiset<int> s;
		for(int i=0;i<n*2-1;i++) s.insert(a[i]);
		bool flag=0;
		for(int i=0;i<n*2-1;i++){
			s.erase(s.find(a[i]));
			vector<pii> res=solve(s,a[n*2-1]);
			s.insert(a[i]);
			if(res.size()){
				printf("YES\n%d\n%d %d\n",a[n*2-1]+a[i],a[n*2-1],a[i]);
				for(pii j:res) printf("%d %d\n",j.first,j.second);
				flag=1;
				break;
			}
		}
		if(!flag) printf("NO\n");
	}
	return 0;
}