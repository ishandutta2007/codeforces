#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int T,n,m,x,y;
int main(){
	cin>>T;
	while(T--){
		scanf("%d%d",&n,&m);
		map<int,int>ma;
		for(int i=1;i<=m;i++){
			scanf("%d%d",&x,&y);
			ma[y]|=(1<<(x-1));
		}
		map<int,int>::iterator it;
		int tw=0;
		int jo=0;
		bool flag=0;
		ma[2000000000]=3; 
		for(it=ma.begin();it!=ma.end();it++){
			int S=it->second;
			if(tw and S!=3){
				if(jo ==((it->first +S)&1))flag=1;
				tw=0;
			}
			else if(S==3){
				if(tw==1)flag=1;
				tw=0;
			}
			else{
				tw=1;
				jo=(it->first +S)&1;
			}
		}
		if(!flag)puts("YES");
		else puts("NO");
	}
	return 0;
}