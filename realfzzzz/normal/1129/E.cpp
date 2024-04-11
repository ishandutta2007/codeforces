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
const int maxn=500+5;
int n,size[maxn],ord[maxn];
vector<int> s;
bool check(int u,int l,int r){
	printf("1\n1\n%d\n",r-l+1);
	for(int i=l;i<=r;i++) printf("%d ",s[i]);
	printf("\n%d\n",u);
	fflush(stdout);
	return readint();
}
int main(){
	#ifdef LOCAL
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	#endif
	n=readint();
	size[1]=n;
	for(int i=2;i<=n;i++){
		printf("1\n1\n%d\n",n-1);
		for(int j=2;j<=n;j++) printf("%d ",j);
		printf("\n%d\n",i);
		fflush(stdout);
		size[i]=readint();
	}
	for(int i=1;i<=n;i++) ord[i]=i;
	sort(ord+1,ord+n+1,[](int a,int b){
		return size[a]<size[b];
	});
	vector<pair<int,int>> ans;
	for(int i=1;i<=n;i++){
		while(s.size()&&check(ord[i],0,s.size()-1)){
			int l=0,r=s.size()-1;
			while(l<r){
				int mid=l+(r-l)/2;
				if(check(ord[i],l,mid)) r=mid;
				else l=mid+1;
			}
			ans.push_back({ord[i],s[r]});
			s.erase(s.begin()+r);
		}
		s.push_back(ord[i]);
	}
	printf("ANSWER\n");
	for(auto i:ans) printf("%d %d\n",i.first,i.second);
	return 0;
}