#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		pair<int,int>mn={1e9,1e9},mx={-1e9,-1e9};
		tuple<int,int,int>tmp;
		rep(i,0,n-1){
			int l,r,c;
			scanf("%d%d%d",&l,&r,&c);
			if(i==0){
				mn={l,c};
				mx={r,-c};
				tmp={l,r,c};
			}else{
				mn=min(mn,{l,c});
				mx=max(mx,{r,-c});
				if(l<get<0>(tmp)){
					tmp={l,r,c};
				}else if(l==get<0>(tmp)){
					if(r>get<1>(tmp)){
						tmp={l,r,c};
					}else if(r==get<1>(tmp)){
						if(c<get<2>(tmp)){
							tmp={l,r,c};
						}
					}
				}
			}
			int ans=mn.second-mx.second;
			if(mn.first==get<0>(tmp)&&mx.first==get<1>(tmp)){
				ans=min(ans,get<2>(tmp));
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}