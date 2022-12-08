#include <iostream>

using namespace std;

const int MAXN=2111;

int N;
int Num[MAXN];
int Cnt2[MAXN], Cnt1[MAXN], Sum[MAXN];
int CCnt1[MAXN], CCnt2[MAXN];
int Map[MAXN][13];
int ANS=0;

int Ask(int l, int r){
	int k=0;
	while((1<<(k+1)<(r-l+1)))	++k;
	return max(Map[l][k], Map[r-(1<<k)+1][k]);
}

int Calc(int l, int r){
	int ret=Ask(l, r);
	ret-=Cnt2[l];ret-=Cnt1[r];
	ret+=CCnt1[l];ret+=CCnt2[r];
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> N;
	for(int i=1;i<=N;++i)	cin >> Num[i];
	
	CCnt1[0]=0;
	for(int i=1;i<=N;++i){
		if(Num[i]==1)	CCnt1[i]=CCnt1[i-1]+1;
		else	CCnt1[i]=CCnt1[i-1];
	}
	
	CCnt2[N]=0;
	for(int i=N-1;i>=0;--i){
		if(Num[i+1]==2)	CCnt2[i]=CCnt2[i+1]+1;
		else	CCnt2[i]=CCnt2[i+1];
	}
	
	Cnt2[0]=0;
	for(int i=1;i<=N;++i){
		if(Num[i]==2)	Cnt2[i]=Cnt2[i-1]+1;
		else	Cnt2[i]=Cnt2[i-1];
	}
	
	Cnt1[N]=0;
	for(int i=N-1;i>=0;--i){
		if(Num[i+1]==1)	Cnt1[i]=Cnt1[i+1]+1;
		else	Cnt1[i]=Cnt1[i+1];
	}
	
	for(int i=0;i<=N;++i)
		Sum[i]=Cnt1[i]+Cnt2[i];
	
	for(int i=0;i<=N;++i)	Map[i][0]=Sum[i];
	for(int i=1;i<=12;++i)
		for(int j=0;(j+(1<<i)-1)<=N;++j)
			Map[j][i]=max(Map[j][i-1], Map[j+(1<<(i-1))][i-1]);
	
	for(int l=0;l<N;++l)
		for(int r=l+1;r<=N;++r){
			ANS=max(ANS, Calc(l, r));
		}
	
	cout << ANS << endl;
	
	return 0;
}