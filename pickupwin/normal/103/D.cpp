#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN=311111;

int N, M;
int Lim;
long long Num[MAXN];
long long F[MAXN];

struct Query{
	int a, b, id;
	long long ans;
} Q[MAXN];

bool cmpb(Query A, Query B){
	return A.b<B.b;
}

bool cmpid(Query A, Query B){
	return A.id<B.id;
}

long long Jump(Query A){
	long long ret=0LL;
	for(int i=A.a;i<=N;i+=A.b)
		ret+=Num[i];
	return ret;
}

void Calc(int k){
	for(int i=N;i>=1;--i)
		F[i]=Num[i]+F[i+k];
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> N;
	for(int i=1;i<=N;++i)	cin >> Num[i];
	for(Lim=0;Lim*Lim<N;++Lim);
	cin >> M;
	for(int i=1;i<=M;++i){
		cin >> Q[i].a >> Q[i].b;
		Q[i].id=i;
	}
	
	sort(Q+1, Q+M+1, cmpb);
	
	for(int i=1;i<=M;++i){
		if(Q[i].b>Lim){
			Q[i].ans=Jump(Q[i]);
			continue;
		}
		if(i==1 || Q[i].b!=Q[i-1].b)
			Calc(Q[i].b);
		Q[i].ans=F[Q[i].a];
	}
	
	sort(Q+1, Q+M+1, cmpid);
	
	for(int i=1;i<=M;++i)
		cout << Q[i].ans << endl;
	
	return 0;
}