#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN=200111;
const int MAXM=200111;

int N, M;
long long Ans[MAXM];

struct Seg{
	long long l, r;
} S[MAXN];

struct Query{
	long long p, r;
	int id;
} Q[MAXM];

bool cmpp(Query A, Query B){
	return A.p>B.p;
}

struct Node{
	long long l, r;
	long long sl, sr;
} St[MAXN];

int Top;

void Push(Seg S){
	while(Top>0 && S.r>=St[Top].l)	{S.r=max(S.r, St[Top].r);--Top;}
	++Top;St[Top].l=S.l;St[Top].r=S.r;
	St[Top].sl=St[Top-1].sl+S.l;St[Top].sr=St[Top-1].sr+S.r;
}

long long Ask(long long p){
	int l=1, r=Top, m;
	while(l<r){
		m=(l+r)>>1;
		if(St[m].l<=p)	r=m;
		else	l=m+1;
	}
	m=(l+r)>>1;
	long long len=St[Top].l-St[m].l-(St[Top].sl-St[m].sl-St[Top].sr+St[m].sr);
	len=-len;
	if(p>St[m].r)	len+=(p-St[m].r);
	return len;
}

void show(){
	for(int i=Top;i>=0;--i){
		cout << "(" << St[i].l << "," << St[i].r << ")" << " ";
	}
	cout << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> N;
	for(int i=1, p, l;i<=N;++i){
		cin >> p >> l;
		S[i].l=p;S[i].r=p+l;
	}
	
	cin >> M;
	for(int i=1, a, b;i<=M;++i){
		cin >> a >> b;
		Q[i].p=a;Q[i].r=S[b].l;
		Q[i].id=i;
	}
	
	sort(Q+1, Q+M+1, cmpp);
	
	for(int i=1, j=N;i<=M;++i){
		while(j>=1 && j>=Q[i].p)	{Push(S[j]);--j;}
		//cout << j << "---";show();
		Ans[Q[i].id]=Ask(Q[i].r);
	}
	
	for(int i=1;i<=M;++i)
		cout << Ans[i] << endl;
	
	return 0;
}