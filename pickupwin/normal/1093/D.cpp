#include <iostream>

using namespace std;

const int MAXN=300111;
const int MAXM=300111;
const int MOD=998244353;

int mul(int a, int b){
	return (int)((1LL*a*b)%(1LL*MOD));
}

int sr;
int sum(int a, int b){
	sr=a+b;
	if(sr>=MOD)	sr-=MOD;
	return sr;
}

int Bin[MAXN];

int T;

int N, M;

int Ans;
bool Win;

struct Vert{
	int FE;
	int Co;
	bool Vis;
} V[MAXN];

struct Edge{
	int x, y, next;
} E[MAXM<<1];

int Ecnt;

void addE(int a, int b){
	++Ecnt;
	E[Ecnt].x=a;E[Ecnt].y=b;E[Ecnt].next=V[a].FE;V[a].FE=Ecnt;
}

bool Test(int e){
	return V[E[e].x].Co!=V[E[e].y].Co;
}

void Init(){
	Ecnt=0;
	for(int i=1;i<=N;++i){
		V[i].FE=0;
		V[i].Co=-1;
		V[i].Vis=false;
	}
}

void DFS(int at){
	for(int k=V[at].FE, to;k>0;k=E[k].next){
		to=E[k].y;
		if(V[to].Co<0){
			V[to].Co=!V[at].Co;
			DFS(to);
		}
	}
}

int Cnt[2];

void Push(){
	Ans=mul(Ans, sum(Bin[Cnt[0]], Bin[Cnt[1]]));
}

void Count(int at){
	V[at].Vis=true;
	++Cnt[V[at].Co];
	for(int k=V[at].FE, to;k>0;k=E[k].next){
		to=E[k].y;
		if(V[to].Vis)	continue;
		Count(to);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	
	N=300000;
	
	Bin[0]=1;
	for(int i=1;i<=N;++i)	Bin[i]=sum(Bin[i-1], Bin[i-1]);
	
	cin >> T;
	
	while(T--){
		
		
		cin >> N >> M;
		
		
		Init();
		
		
		Win=true;
		
		for(int i=1, a, b;i<=M;++i){
			cin >> a >> b;
			addE(a, b);addE(b, a);
		}
		
		for(int i=1;i<=N;++i){
			if(V[i].Co<0){
				V[i].Co=0;
				DFS(i);
			}
		}
		
		for(int i=1;i<=Ecnt;++i){
			if(!Test(i)){
				Win=false;
			}
		}
		
		if(!Win){
			cout << "0" << endl;
			continue;
		}
		
		Ans=1;
		
		for(int i=1;i<=N;++i){
			if(!V[i].Vis){
				Cnt[0]=Cnt[1]=0;
				Count(i);
				Push();
			}
		}
		
		cout << Ans << endl;
		
	}
	
	
	
	return 0;
}