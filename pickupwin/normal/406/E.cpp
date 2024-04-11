#include <algorithm>
#include <cstdio>

using std::sort;

const int MAXM=100111;

int N, M;

int Num[MAXM];

struct Pair{
	int v, c;
	Pair(){}
	Pair(int _v, int _c){v=_v;c=_c;}
} P[MAXM<<1];

int Pc;

int Sum[MAXM<<1];

long long Calc(int a, int b){
	return 1LL*(M-a-b)*a*b+1LL*a*b*(b-1)/2LL+1LL*b*a*(a-1)/2LL;
}

int Find(int v){
	for(int i=1;i<=Pc;++i)	if(P[i].v==v)	return i;
	return 0;
}

int Bound(int v){
	if(P[1].v>v)	return 0;
	int l=1, r=Pc, m;
	while(l<r){
		m=(l+r)>>1;
		if(P[m+1].v<=v)	l=m+1;
		else	r=m;
	}
	m=(l+r)>>1;
	return m;
}

long long CC(int n){
	return 1LL*n*(n-1)/2LL;
}

long long CCC(int n){
	return 1LL*n*(n-1)*(n-2)/6LL;
}

long long Search1(){
	long long ret=0LL;
	for(int i=1;i<=Pc;++i){
		if(P[i].v>0 && P[i].v<N){
			ret+=1LL*P[i].c*(Sum[Bound(P[i].v+N)]-Sum[Bound(N)]);
		}
	}
	return ret;
}

long long Search2(){
	long long ret=0LL;
	for(int i=1;i<=Pc;++i){
		if(P[i].v>N && P[i].v<(N<<1)){
			ret+=1LL*P[i].c*(Sum[Bound(P[i].v-N)]-Sum[Bound(0)]);
		}
	}
	return ret;
}

long long Search3(){
	long long ret=0LL;
	for(int i=1;i<=Pc;++i){
		if(P[i].v>0 && P[i].v<N){
			ret+=1LL*P[i].c*(Sum[Bound(P[i].v+N)]-Sum[Bound(N)])*(Sum[Bound((N<<1)-1)]-Sum[Bound(P[i].v+N-1)]);
			ret-=1LL*P[i].c*(Sum[Bound(P[i].v+N)]-Sum[Bound(P[i].v+N-1)]);
			ret-=1LL*P[i].c*CC(Sum[Bound(P[i].v+N)]-Sum[Bound(P[i].v+N-1)]);
		}
	}
	return ret;
}

long long Search4(){
	long long ret=0LL;
	for(int i=1;i<=Pc;++i){
		if(P[i].v>N && P[i].v<(N<<1)){
			ret+=1LL*P[i].c*(Sum[Bound(P[i].v-N)]-Sum[Bound(0)])*(Sum[Bound(N-1)]-Sum[Bound(P[i].v-N-1)]);
			ret-=1LL*P[i].c*(Sum[Bound(P[i].v-N)]-Sum[Bound(P[i].v-N-1)]);
			ret-=1LL*P[i].c*CC(Sum[Bound(P[i].v-N)]-Sum[Bound(P[i].v-N-1)]);
		}
	}
	return ret;
}

long long V(int p){
	return (long long)(P[p].v)+(long long)((p>Pc)?(N<<1):0);
}

int main(){
	
	scanf("%d%d", &N, &M);
	for(int i=1, v, c;i<=M;++i){
		scanf("%d%d", &v, &c);
		Num[i]=(v+1)*N-c;
	}
	
	sort(Num+1, Num+M+1);
	
	for(int i=1;i<=M;++i){
		if(i==1 || Num[i]!=Num[i-1])
			P[++Pc]=Pair(Num[i], 1);
		else	++P[Pc].c;
	}
	
	for(int i=1;i<=Pc;++i)	P[Pc+i]=P[i];
	
	Sum[0]=0;
	for(int i=1;i<=Pc<<1;++i)	Sum[i]=Sum[i-1]+P[i].c;
	
	for(int i=1, j=0;i<=Pc;++i){
		while(j<(Pc<<1) && V(j+1)<(long long)(P[i].v)+(long long)(N))	++j;
		if(Sum[j]-Sum[i-1]==M){
			if(i==j)	printf("%I64d\n", CCC(P[i].c));
			else	printf("%I64d\n", Calc(P[i].c, P[j].c));
			return 0;
		}
	}
	
	long long Ans=0LL;
	int p=Find(0), q=Find(N);
	if(p && q)	Ans+=Calc(P[p].c, P[q].c);
	if(p)	Ans+=Search1()*P[p].c;
	if(q)	Ans+=Search2()*P[q].c;
	Ans+=Search3()+Search4();
	
	printf("%I64d\n", Ans);
	
	return 0;
}