#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN=200111;
const int MAXM=1111111;
const int MAXL=5111111;

int N, M;
int A[MAXN];
vector<int> D[MAXN];
int C[MAXN];

int L;
bool isP[MAXL];
int P[MAXL], Pc;
vector<int> Son[MAXL];

void Deal(int &a, vector<int> &t){
	int r=1;
	vector<int> &v=Son[a];
	for(int i=0, s=v.size(), c;i<s;++i){
		//cout << i << " " << v[i] << endl;
		c=0;
		while(a%v[i]==0)	{++c;a/=v[i];}
		if(c&1)	{r*=v[i];t.push_back(v[i]);}
	}
	a=r;
}

int Pos[MAXL][8], Del[MAXL];



namespace Seg{
	
	struct Data{
		int l, r, v;
	} D[MAXN*15];
	
	bool operator < (Data A, Data B){
		return A.r<B.r;
	}
	
	int Dc;
	
	void addD(int l, int r, int v){
		//cout << l << " " << r << " " << v << endl;
		++Dc;
		D[Dc].l=l;D[Dc].r=r;D[Dc].v=v;
	}
	
	struct Query{
		int l, r, id, ans;
	} Q[MAXM];
	
	bool cmpr(Query A, Query B){
		return A.r<B.r;
	}
	
	bool cmpid(Query A, Query B){
		return A.id<B.id;
	}
	
	int C[MAXN];
	
	int lowbit(int a){
		return a&(-a);
	}
	
	void Put(int at, int v){
		//cout << "Put " << at << " " << v << endl;
		for(int i=at;i<=N;i+=lowbit(i))
			C[i]=min(C[i], v);
	}
	
	int Ask(int at){
		int ret=14;
		for(int i=at;i>0;i-=lowbit(i))
			ret=min(ret, C[i]);
		//cout << "Ask " << at << " " << ret << endl;
		return ret;
	}
	
	void Calc(){
		for(int i=1;i<=N;++i)	C[i]=14;
		sort(D+1, D+Dc+1);
		sort(Q+1, Q+M+1, cmpr);
		for(int i=1, j=1;i<=M;++i){
			while(j<=Dc && D[j].r<=Q[i].r){
				Put(N+1-D[j].l, D[j].v);
				++j;
			}
			Q[i].ans=Ask(N+1-Q[i].l);
		}
		sort(Q+1, Q+M+1, cmpid);
	}
	
	void Show(){
		for(int i=1;i<=M;++i){
			printf("%d\n", Q[i].ans);
		}
	}
}

void Ask(int at){
	int V=(1<<C[at]);
	int L[15];
	for(int i=0;i<15;++i)	L[i]=0;
	for(int s=0, c, val;s<V;++s){
		val=A[at];c=0;
		for(int i=0;i<C[at];++i){
			if((s>>i)&1)	{val/=D[at][i];++c;}
		}
		for(int i=0;i<8;++i)	if(Pos[val][i])	L[c+i]=max(L[c+i], Pos[val][i]);
	}
	for(int i=0;i<15;++i){
		if(L[i]){
			Seg::addD(L[i], at, i);
		}
	}
}

void Push(int at){
	int V=(1<<C[at]);
	for(int s=0, c, val;s<V;++s){
		val=A[at];c=0;
		for(int i=0;i<C[at];++i){
			if((s>>i)&1)	{val/=D[at][i];++c;}
		}
		Pos[val][c]=at;
	}
}

int main(){
	
	L=5032107;
	//L=500;
	
	for(int i=2;i<=L;++i)	isP[i]=true;
	for(int i=2;i<=L;++i){
		if(isP[i])	P[++Pc]=i;
		for(int j=1;j<=Pc && P[j]<=L/i;++j){
			isP[i*P[j]]=false;
			if(i%P[j]==0)	break;
		}
	}
	
	for(int i=1;i<=Pc;++i)
		for(int j=P[i];j<=L;j+=P[i])
			Son[j].push_back(P[i]);
	
	cin >> N >> M;
	
	for(int i=1;i<=N;++i){
		cin >> A[i];
		Deal(A[i], D[i]);
		C[i]=D[i].size();
	}
	
	for(int i=1;i<=N;++i){
		Ask(i);
		Push(i);
	}
	
	for(int i=1;i<=M;++i){
		using Seg::Q;
		cin >> Q[i].l >> Q[i].r;
		Q[i].id=i;
	}
	
	Seg::Calc();
	
	Seg::Show();
	
	return 0;
}