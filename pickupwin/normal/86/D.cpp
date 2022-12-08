#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN=211111;
const int MAXM=211111;
const int MAXV=1111111;

int N, M;
int Num[MAXN];
int Bs;
int L=1, R=0;
int Cnt[MAXV];
long long Val=0LL;

struct Query{
	int l, r, id;
	long long ans;
} Q[MAXM];

bool cmpp(Query A, Query B){
	if((A.l/Bs)==(B.l/Bs))	return A.r<B.r;
	return (A.l/Bs)<(B.l/Bs);
}

bool cmpid(Query A, Query B){
	return A.id<B.id;
}

void calc(int s, int t, bool in){
	for(int i=s, a;i<=t;++i){
		a=Cnt[Num[i]];
		if(in){
			Val+=(long long)((a<<1)+1)*(long long)(Num[i]);
			++Cnt[Num[i]];
		}
		else{
			Val-=(long long)((a<<1)-1)*(long long)(Num[i]);
			--Cnt[Num[i]];
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> N >> M;
	for(int i=1;i<=N;++i)	cin >> Num[i];
	for(Bs=0;Bs*Bs<N;++Bs);
	for(int i=1;i<=M;++i)	cin >> Q[i].l >> Q[i].r, Q[i].id=i;
	sort(Q+1, Q+M+1, cmpp);
	for(int i=1;i<=M;++i){
		//cout << L << " " << R << " " << Val << endl;
		calc(min(L, Q[i].l), max(L, Q[i].l)-1, (Q[i].l<L));
		L=Q[i].l;
		//cout << L << " " << R << " " << Val << endl;
		calc(min(R, Q[i].r)+1, max(R, Q[i].r), (Q[i].r>R));
		R=Q[i].r;
		//cout << L << " " << R << " " << Val << endl;
		Q[i].ans=Val;
	}
	sort(Q+1, Q+M+1, cmpid);
	for(int i=1;i<=M;++i)
		cout << Q[i].ans << endl;
	
	return 0;
}

/*
20 8
1 2 1 2 1 2 1 2 1 2 1 2 1 2 1 2 1 2 1 2
4 15
1 2
2 20
7 7
13 18
7 7
3 19
3 8

108
3
281
1
27
1
209
27

*/