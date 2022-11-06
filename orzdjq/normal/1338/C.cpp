#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
using namespace std;
inline int read(){
	int v=0,f=1;
	char c=getchar();
	while (c<'0' || c>'9'){
		if (c=='-') f=-1;
		c=getchar();
	}
	while (c>='0' && c<='9'){
		v=v*10+c-'0';
		c=getchar();
	}
	return v*f;
}
int H;
void mian(int _=-1){
	LL n;
	scanf("%lld",&n);
	if (n<=3){
		printf("%lld\n",n);
		return;
	}
	LL pos=(n-1)/3+1;
	H=n-pos*3+3;
	
	int w=0;
	while (1){
		if (pos<=(1ll<<w)){
			break;
		}
		pos-=1ll<<w;
		w+=2;
	}
	
	LL st=1ll<<w;
	//cout<<"HH"<<' '<<H<<endl;
	if (H==1){
		printf("%lld\n",st+pos-1);
		return;
	}
	LL A=0;
	pos--;
//	cout<<pos<<endl;
	for (int i=w-2;i>=0;i-=2){
		LL CW=1ll<<i;
		LL NW=1ll<<(i+2);
		LL tmp=pos%NW/CW;
		if (tmp==0) ;
		else if (tmp==1) A|=2ll<<i;
		else if (tmp==2) A|=3ll<<i;
		else A|=1ll<<i;
	}
	A+=2ll<<w;
	if (H==2){
		printf("%lld\n",A);
		return;
	}
	if (H==3){
		//cout<<A<<' '<<st+pos-1<<endl;
		printf("%lld\n",A^(st+pos));
		return;
	}
}
int main(){
	int t;
	scanf("%d",&t);
	for (int i=1;i<=t;i++){
		mian();
	}
}