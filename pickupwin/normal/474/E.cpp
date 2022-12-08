#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN=111111;

int N;
long long D;

struct Pillar{
	long long height;
	int id, rank;
	int left, right;
} P[MAXN];

bool cmph(Pillar A, Pillar B){
	if(A.height==B.height)	return A.id<B.id;
	return A.height<B.height;
}

bool cmpid(Pillar A, Pillar B){
	return A.id<B.id;
}

struct Data{
	int v, at;
} C[MAXN], invC[MAXN], Zero, ANS[MAXN];

Data max(Data A, Data B){
	return (A.v>B.v)?A:B;
}

int lowbit(int a){
	return a&(-a);
}

void Put(int at, int val){
	Data p;p.v=val;p.at=at;
	for(int i=at;i<=N;i+=lowbit(i))
		C[i]=max(C[i], p);
}

void invPut(int at, int val){
	Data p;p.v=val;p.at=at;at=N-at+1;
	for(int i=at;i<=N;i+=lowbit(i))
		invC[i]=max(invC[i], p);
}

Data Ask(int at){
	Data ret=Zero;
	for(int i=at;i>0;i-=lowbit(i))
		ret=max(ret, C[i]);
	return ret;
}

Data invAsk(int at){
	at=N-at+1;Data ret=Zero;
	for(int i=at;i>0;i-=lowbit(i))
		ret=max(ret, invC[i]);
		//ret=max(ret, C[i]);
	return ret;
}

int Answer=0;
int Out[MAXN], Ocnt=0;

int main(){
	ios_base::sync_with_stdio(false);
	
	Zero.v=0;Zero.at=-1;
	
	cin >> N;
	cin >> D;
	
	for(int i=1;i<=N;++i)	cin >> P[i].height;
	for(int i=1;i<=N;++i)	P[i].id=i;
	
	sort(P+1, P+N+1, cmph);
	
	for(int i=1, j=0;i<=N;++i){
		//while(P[j+1].height+D<=P[i].height)	++j;
		while(j+1<=N && P[j+1].height+D<=P[i].height)	++j;
		P[i].left=j;
	}
	
	for(int i=N, j=N+1;i>=1;--i){
		//while(P[j-1].height-D>=P[i].height)	--j;
		while(j-1>=1 && P[j-1].height-D>=P[i].height)	--j;
		P[i].right=j;
	}
	
	for(int i=1;i<=N;++i)	P[i].rank=i;
	
	sort(P+1, P+N+1, cmpid);
	
	//for(int i=1;i<=N;++i)	cout << P[i].left << " " << P[i].right << endl;
	
	for(int i=1;i<=N;++i){
		C[i]=Zero;invC[i]=Zero;
	}
	
	for(int i=1;i<=N;++i){
		//ANS[i]=max(Ask(P[i].left), invAsk(P[i].right));
		//ANS[i]=invAsk(P[i].right);
		//cout << "--" << ANS[i].v << " " << ANS[i].at << endl;
		ANS[i]=max(Ask(P[i].left), invAsk(P[i].right));
		++ANS[i].v;
		Put(P[i].rank, ANS[i].v);
		invPut(P[i].rank, ANS[i].v);
		//cout << ANS[i].v << " " << ANS[i].at << endl;
	}
	
	sort(P+1, P+N+1, cmph);
	
	for(int i=1;i<=N;++i){
		Answer=max(Answer, ANS[i].v);
	}
	
	cout << Answer << endl;
	
	for(int i=1;i<=N;++i){
		if(ANS[i].v==Answer){
			
			for(int at=i;at>0;at=P[ANS[at].at].id)
				Out[++Ocnt]=at;
			
			break;
		}
	}
	
	for(int i=Ocnt;i>=1;--i)	cout << Out[i] << " ";
	cout << endl;
	
	return 0;
}

/*
10 10
1 2 3 4 5 6 7 8 9 1

1
1

*/

/*
15 0
1 6 1 1516 1516919198514 5161 1516 15151 115611514 4984956910 9916519 56165133 16551964984196 161651616 132123

15
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15

*/