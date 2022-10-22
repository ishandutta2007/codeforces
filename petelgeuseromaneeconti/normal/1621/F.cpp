#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
using LL=long long;
const int N=100005;
int T,n,wa,wb,wc;
char s[N];
int get_time(int w1,int w2,int w3,deque<int>vec,int opt){
	int tt=0;
	while(1){
		++tt;
		if(opt==1){
			if(w2>=1){
				w2-=1;
			}else{
				break;
			}
		}else{
			if(!vec.empty()){
				if(vec[0]==1){
					vec.pop_front();
					++w2;
				}else{
					vec[0]-=1;
				}
			}else if(w1){
				--w1;
			}else if(w3){
				--w3;
			}else{
				break;
			}
		}
		opt^=1;
	}
	return tt;
}
LL sol(int w1,int w2,int w3,deque<int>vec,int opt){
	int max_tt=get_time(w1,w2,w3,vec,opt),tt=0;
	LL res=0,mx=0;
	for(auto&x:vec){
		w3+=1;
		w1+=x-1;
	}
	while(1){
		if(++tt>=max_tt)break;
		if(opt==1){
			if(w2>=1){
				w2-=1;
				res+=wb;
			}else{
				res=res-wa-wc+wb; //
				w1+=1;
			}
		}else{
			if(w1>=1){
				w1-=1;
				res+=wa;
			}else{
				w2+=1;
				res-=wc;
			}
		}
		mx=max(mx,res);
		opt^=1;
	}
	return mx;
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d",&n,&wa,&wb,&wc);
		scanf("%s",s+1);
		int w1=0,w2=0,w3=0;
		deque<int>vec;
		for(int i=1,j;i<=n;i=j){
			j=i+1;
			while(j<=n&&s[i]==s[j])++j;
			if(s[i]=='0'){
				if(i!=1&&j<=n){
					vec.pb(j-i);
				}else{
					w1+=j-i-1;
					w3+=1;
				}
			}else{
				w2+=j-i-1;
			}
		}
		sort(vec.begin(),vec.end());
		printf("%lld\n",max(sol(w1,w2,w3,vec,0),sol(w1,w2,w3,vec,1)));
	}
	return 0;
}