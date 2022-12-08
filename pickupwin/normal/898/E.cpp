#include <iostream>
using namespace std;
const int MAXV=33333, MAXN=211111;
long long lmin(long long a, long long b){
	return (a>b)?b:a;
}
long long labs(long long a){
	return (a>0)?a:(-a);
}
long long Sq[MAXV];
long long Bsearch(long long k){
	int left=0, right=MAXV-1, mid;
	while(left<right){
		mid=(left+right)>>1;
		if(Sq[mid+1]>k)	right=mid;
		else	left=mid+1;	
	}
	mid=(left+right)>>1;
	return lmin(labs(Sq[mid]-k), labs(Sq[mid+1]-k));
}
int N, M;
struct Pile{
	long long Num, CosttoS;
} P[MAXN];
bool operator < (Pile a, Pile b){
	if(a.CosttoS==b.CosttoS)	return a.Num<b.Num;
	else	return a.CosttoS<b.CosttoS;
}
void Qsort(int l, int r){
	int i=l, j=r;
	Pile test=P[(l+r)>>1], temp;
	while(i<=j){
		while(P[i]<test)	++i;
		while(test<P[j])	--j;
		if(i<=j){
			temp=P[i];P[i]=P[j];P[j]=temp;
			++i;--j;
		}
	}
	if(l<j)	Qsort(l, j);
	if(i<r)	Qsort(i, r);
}
long long ANS=0LL;
int main(){
	ios_base::sync_with_stdio(false);
	for(long long i=0LL;i<33333LL;++i)	Sq[i]=i*i;
	cin >> N;M=(N>>1);
	for(int i=1;i<=N;++i){
		cin >> P[i].Num;
		P[i].CosttoS=Bsearch(P[i].Num);
	}
	Qsort(1, N);
	for(int i=1;i<=M;++i)	ANS+=P[i].CosttoS;
	for(int i=M+1;i<=N;++i){
		if(P[i].CosttoS==0LL){
			if(P[i].Num==0LL)	ANS+=2LL;
			else	ANS+=1LL;
		}
	}
	cout << ANS << endl;
	return 0;
}