#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
multiset<int> s;
ll d[35];

void add(int x,int c){
	for(int i=0;i<=30;i++) if(x<=(1<<i)) d[i]+=c;
}

int main(){
	int q=readint();
	char opt[3]; int x;
	while(q--){
		scanf("%s",opt); x=readint();
		if(opt[0]=='+') add(x,x),n++,s.insert(x);
		else add(x,-x),n--,s.erase(s.find(x));
		int ans=0,lst=-1;
		if(n>0) ans=n-1;
		for(int i=0;i<=30;i++){
			if(!d[i]||lst>(1<<i)) continue;
			int xx=*s.upper_bound(1ll<<i);
//			cout<<"TEST "<<d[i]<<' '<<xx<<endl;
			if(d[i]*2<xx&&lst!=xx) ans--,lst=xx;
		}
		printf("%d\n",ans);
	}
	return 0;
}