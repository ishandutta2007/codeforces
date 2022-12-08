#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN=3011;
const int MAXM=3011;
const long long LONF=4567891012345678910LL;

int N, M;

struct Note{
	int To;
	long long Val;
	int id;
} T[MAXN];

bool cmpt(Note A, Note B){
	if(A.To==B.To)	return A.Val<B.Val;
	return A.To<B.To;
}

bool cmpv(Note A, Note B){
	return A.Val<B.Val;
}

struct Party{
	int Get;
	long long Deal[MAXN];
	int Is[MAXN];
} P[MAXM];

long long Ans=LONF, Temp;

bool Vis[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> N >> M;
	for(int i=1;i<=N;++i){
		cin >> T[i].To >> T[i].Val;
		++P[T[i].To].Get;
		T[i].id=i;
	}
	
	sort(T+1, T+N+1, cmpt);
	
	for(int i=1, j=1;i<=N;++i, ++j){
		if(i==1 || T[i].To!=T[i-1].To)	j=1;
		P[T[i].To].Deal[j]=P[T[i].To].Deal[j-1]+T[i].Val;
		P[T[i].To].Is[j]=T[i].id;
	}
	
	sort(T+1, T+N+1, cmpv);
	
	for(int h=P[1].Get, v=0;h<=N;++h, v=h-P[1].Get){
		Temp=0LL;
		for(int i=1;i<=N;++i)	Vis[i]=false;
		for(int i=2, k;i<=M;++i){
			if(h<=P[i].Get){
				k=(P[i].Get-h+1);
				v-=k;
				Temp+=P[i].Deal[k];
				for(int p=1;p<=k;++p)	Vis[P[i].Is[p]]=true;
			}
		}
		if(v<0)	{/*cout << h << "!" << endl;*/continue;}
		for(int i=1;i<=N && v>0;++i){
			if(!Vis[T[i].id] && T[i].To!=1){
				--v;
				Temp+=T[i].Val;
			}
		}
		Ans=min(Ans, Temp);
	}
	
	cout << Ans << endl;
	
	return 0;
}