#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

const int MAXN=111111;

int N, Num[MAXN];
int M;

int Scnt=0, Tcnt=0, Acnt=0;

struct Temp{
	int Val;
	long long Cnt;
} S[MAXN], T[MAXN], Ans[MAXN*133];

bool operator < (Temp A, Temp B){
	return A.Val<B.Val;
}

int gcd(int a, int b){
	return (b==0)?a:gcd(b, a%b);
}

struct Query{
	int x, id;
	long long ans;
} Q[MAXN<<2];

bool cmpx(Query A, Query B){
	return A.x<B.x;
}

bool cmpid(Query A, Query B){
	return A.id<B.id;
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> N;
	for(int i=1;i<=N;++i)	cin >> Num[i];
	
	for(int i=N;i>=1;--i){
		Tcnt=Scnt;
		for(int j=1;j<=Tcnt;++j){
			T[j].Val=gcd(S[j].Val, Num[i]);
			T[j].Cnt=S[j].Cnt;
		}
		++Tcnt;
		T[Tcnt].Val=Num[i];
		T[Tcnt].Cnt=1LL;
		sort(T+1, T+Tcnt+1);
		Scnt=0;
		for(int i=1;i<=Tcnt;++i){
			if(T[i].Val!=T[i-1].Val){
				++Scnt;
				S[Scnt].Val=T[i].Val;
				S[Scnt].Cnt=T[i].Cnt;
			}
			else{
				S[Scnt].Cnt+=T[i].Cnt;
			}
		}
		for(int i=1;i<=Scnt;++i){
			++Acnt;
			Ans[Acnt]=S[i];
		}
//		if(Num[2]==87100 && i<=10)
//			cout << Acnt << endl;
//		cout << "----------" << i << endl;
//		for(int i=1;i<=Scnt;++i){
//			cout << S[i].Val << " ";
//		}
//		cout << endl << "------------" << endl;
	}
	
	assert(Acnt<MAXN*133);
	
	//if(Num[2]==87100)
	//	cout << Ans[1].Val << " " << Ans[2].Val << " " << Ans[10].Val << " " << Ans[101].Val << " " << Ans[555].Val << endl;
	
	sort(Ans+1, Ans+Acnt+1);
	
	//if(Num[2]==87100)
	//	cout << Ans[1].Val << " " << Ans[2].Val << " " << Ans[10].Val << " " << Ans[101].Val << " " << Ans[555].Val << endl;
	
	cin >> M;
	for(int i=1;i<=M;++i){
		cin >> Q[i].x;
		Q[i].id=i;
	}
	
	sort(Q+1, Q+M+1, cmpx);
	
	for(int i=1, j=1;i<=M;++i){
		if(Q[i].x==Q[i-1].x){
			Q[i].ans=Q[i-1].ans;
			continue;
		}
		Q[i].ans=0LL;
		while(j<=Acnt && Ans[j].Val<=Q[i].x){
			if(Ans[j].Val==Q[i].x){
				Q[i].ans+=Ans[j].Cnt;
			}
			++j;
		}
	}
	
	sort(Q+1, Q+M+1, cmpid);
	
//	long long test=0LL;
//	for(int i=1;i<=10;++i)	test+=Q[i].ans;
//	
//	if(test==0LL){
//		cout << Acnt << endl;
//		for(int i=1;i<=10;++i)
//			cout << S[i].Val << endl;
//		return 0;
//	}
	
	for(int i=1;i<=M;++i)
		cout << Q[i].ans << endl;
	
	return 0;
}