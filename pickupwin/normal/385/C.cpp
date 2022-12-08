#include <iostream>

using namespace std;

const int MAXN=1111111;
const int MAXV=11111111;
const int MAXP=677777;
const int INF=1034567890;

int N, M;
int E[MAXV];
bool isP[MAXV];
int P[MAXP], ANS[MAXP];
long long Sum[MAXP];
int Pcnt;

int Find(long long k){
	if(k>=(long long)(INF))	return Pcnt+1;
	int kk=(int)(k);
	int Left=0, Right=Pcnt+1, Mid;
	while(Left<Right){
		Mid=(Left+Right)>>1;
		if(P[Mid+1]<=kk)	Left=Mid+1;
		else	Right=Mid;
	}
	Mid=(Left+Right)>>1;
	return Mid;
}

long long Ask(long long l, long long r){
	int rr=Find(r);
	int ll=Find(l-1LL);
	//cout << ll << " " << rr << endl;
	return Sum[rr]-Sum[ll];
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> N;
	for(int i=1, n;i<=N;++i){
		cin >> n;
		++E[n];
	}
	
	for(int i=2;i<=10000000;++i)	isP[i]=true;
	for(int i=2;i<=10000000;++i){
		if(isP[i])	P[++Pcnt]=i;
		for(int j=1;j<=Pcnt && P[j]*i<=10000000;++j){
			isP[i*P[j]]=false;
			if(i%P[j]==0)	break;
		}
	}
	
	for(int i=1;i<=Pcnt;++i){
		for(int j=P[i];j<=10000000;j+=P[i]){
			ANS[i]+=E[j];
			//if(E[j]!=0)	cout << j << endl;
		}
		//if(ANS[i]!=0)	cout << i << endl;
	}
	
	Sum[0]=0LL;
	for(int i=1;i<=Pcnt;++i)	Sum[i]=Sum[i-1]+(long long)(ANS[i]);
	Sum[Pcnt+1]=Sum[Pcnt];
	
	//for(int i=1;i<=10;++i){
	//	if(ANS[i]!=0)	cout << P[i] << endl;
	//}
	
	P[Pcnt+1]=INF;
	
	cin >> M;
	long long l, r;
	for(int i=1;i<=M;++i){
		cin >> l >> r;
		//if(i==813)	cout << l << r << endl;
		//else
		cout << Ask(l, r) << endl;
	}
	
	return 0;
}

/*
4
2000 2000 2000 2000
1
2 20000000000

8

*/