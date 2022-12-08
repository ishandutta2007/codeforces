#include <iostream>

using namespace std;

const int MAXN=100111;

int N;
int L, Num[MAXN];
int LL, Temp[MAXN];
int Tr[MAXN];
int Cnt=60;

int abs(int a){
	return (a>0)?a:(-a);
}

int I(int k){
	int ret=k+(N>>1);
	if(ret>N)	ret-=N;
	return ret;
}

int ask(int k){
	--Cnt;
	int ret;
	cout << "? " << k << endl;
	cin >> ret;
	return ret;
}

bool Ask(int k){
	Tr[k]=ask(k);
	Tr[I(k)]=ask(I(k));
	if(Tr[k]==Tr[I(k)])	return true;
	return false;
}

void show(int v){
	cout << "! " << v << endl;
}

bool test(int _a, int _b, int _c, int _d){
	bool a=(_a<_c), b=(_b<_d);
	if(a!=b)	return true;
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> N;
	L=N;
	for(int i=1;i<=L;++i)	Num[i]=i;
	if(Ask(Num[1]))	{show(Num[1]);return 0;}
	if(abs(Tr[Num[1]]-Tr[I(Num[1])])&1)	{show(-1);return 0;}
	
	while(L>Cnt){
		if(Ask(Num[1]))	{show(Num[1]);return 0;}
		if(Ask(Num[L>>2]))	{show(Num[L>>2]);return 0;}
		if(test(Tr[Num[1]], Tr[Num[L>>2]], Tr[I(Num[1])], Tr[I(Num[L>>2])])){
			LL=0;
			for(int i=2;i<L>>2;++i)
				Temp[++LL]=Num[i];
			for(int i=1;i<=LL;++i)
				Temp[LL+i]=I(Temp[i]);
			L=LL<<1;
			for(int i=1;i<=L;++i)
				Num[i]=Temp[i];
		}
		else{
			LL=0;
			for(int i=(L>>2)+1;i<=(L>>1);++i)
				Temp[++LL]=Num[i];
			for(int i=1;i<=LL;++i)
				Temp[LL+i]=I(Temp[i]);
			L=LL<<1;
			for(int i=1;i<=L;++i)
				Num[i]=Temp[i];
		}
	}
	
	for(int i=1;i<=(L>>1);++i)
		if(Ask(Num[i]))	{show(Num[i]);return 0;}
	
	return 0;
}