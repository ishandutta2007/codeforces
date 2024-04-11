#include<iostream>
#include<cstdio>
using namespace std;
int t,n;
char a[100001],b[100001];
bool op;
int f[20],ans;
inline int find(int x){
	return x==f[x]?x:f[x]=find(f[x]);
}
int main(){
	cin>>t;
	while(t--){
		scanf("%d%s%s",&n,a+1,b+1);
		op=1;
		for(int i=1;i<=n;i++) op&=a[i]<=b[i];
		if(!op){
			cout<<-1<<endl;
			continue;
		}
		for(int i=0;i<20;i++) f[i]=i;
		for(int i=1;i<=n;i++){
			int x=find(a[i]-'a'),y=find(b[i]-'a');
			if(x!=y) f[x]=y;
		}
		ans=0;
		for(int i=0;i<20;i++) if(find(i)!=i) ans++;
		cout<<ans<<endl;
	}
}