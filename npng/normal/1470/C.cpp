#include <cstdio>
#include <cstring>
const int Maxn=100000;
typedef long long ll;
int n,k;
ll a[Maxn+5];
bool rem;
ll ask(int pos){
	while(pos<1){
		pos+=n;
	}
	while(pos>n){
		pos-=n;
	}
	if(a[pos]!=-1){
		return a[pos];
	}
	printf("? %d\n",pos);
	fflush(stdout);
	ll x;
	scanf("%lld",&x);
	if(rem){
		a[pos]=x;
	}
	return x;
}
void answer(int pos){
	printf("! %d\n",pos);
	fflush(stdout);
}
int main(){
	memset(a,-1,sizeof a);
	scanf("%d%d",&n,&k);
	ask(1);
	int pos,x_l,x_r;
	for(int i=2,j=1;;i=(i+j>n?i+j-n:i+j)){
		if(ask(i)!=k){
			pos=(i-j<1?i-j+n:i-j);
			x_l=i+1;
			x_r=(i+j>n?i+j-n:i+j);
			break;
		}
		j++;
	}
	rem=1;
	if(ask(pos-1)<k&&ask(pos+1)>k&&ask(pos)==k){
		answer(pos);
		return 0;
	}
	for(int i=x_l-1;i!=x_r;i=(i+1>=n?i+1-n:i+1)){
		if(ask(i)<k&&ask(i+2)>k&&ask(i+1)==k){
			answer(i+1);
			break;
		}
	}
	return 0;
}