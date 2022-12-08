#include <iostream>
#include <string>
using namespace std;
const int MAXN=111111, MAXV=11111;
int LNum[30]=
{
	4, 7,
	44, 47, 74, 77,
	444, 447, 474, 477, 744, 747, 774, 777,
	4444, 4447, 4474, 4477, 4744, 4747, 4774, 4777,
	7444, 7447, 7474, 7477, 7744, 7747, 7774, 7777
};
int N, M, Pcnt=0;
int Num[MAXN];
string com;
struct Part{
	int x, y, Data[MAXV], opt, t, Time[MAXV], ans;
	Part(){
		x=0;y=0;opt=0;t=0;ans=-1;
		for(int i=0;i<MAXV;++i)	Time[i]=0, Data[i]=0;
	}
	void calc(){
		for(int i=x;i<=y;++i){
			if(Time[Num[i]]<t){
				Data[Num[i]]=1;Time[Num[i]]=t;
			}
			else	++Data[Num[i]];
		}
	}
	void add(int d){
		ans=-1;
		opt+=d;
	}
	void add(int l, int r, int d){
		ans=-1;
		if(opt<=0 && d<=0)	return;
		++t;
		if(opt>0)	for(int i=x;i<=y;++i)	Num[i]+=opt;
		if(d>0)	for(int i=l;i<=r;++i)	Num[i]+=d;
		calc();
		opt=0;
	}
	int ask(){
		if(ans!=-1)	return ans;
		int ret=0;
		for(int i=0, v;i<30;++i){
			v=LNum[i]-opt;
			if(v<0)	continue;
			if(Time[v]<t)	continue;
			ret+=Data[v];
		}
		ans=ret;
		return ret;
	}
	int ask(int l, int r){
		add(l, r, 0);
		int ret=0;
		for(int i=l;i<=r;++i){
			for(int j=0;j<30;++j){
				if(Num[i]==LNum[j])	++ret;
			}
		}
		return ret;
	}
} P[333];
int L, R, OPX;
int main(){
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	while(Pcnt*Pcnt<N)	++Pcnt;
	for(int i=1;i<=N;++i)	cin >> Num[i];
	for(int i=1;i<=Pcnt;++i){
		P[i].x=(i-1)*Pcnt+1;P[i].y=i*Pcnt;
		P[i].calc();
	}
	for(int i=1;i<=M;++i){
		cin >> com;
		if(com=="count"){
			cin >> L >> R;
			OPX=0;
			for(int p=1, opl, opr;p<=Pcnt;++p){
				opl=max(L, P[p].x);opr=min(R, P[p].y);
				if(opr<opl)	continue;
				if(opl==P[p].x && opr==P[p].y)	OPX+=P[p].ask();
				else	OPX+=P[p].ask(opl, opr);
			}
			cout << OPX << endl;
		}
		else{
			cin >> L >> R >> OPX;
			for(int p=1, opl, opr;p<=Pcnt;++p){
				opl=max(L, P[p].x);opr=min(R, P[p].y);
				if(opr<opl)	continue;
				if(opl==P[p].x && opr==P[p].y)	P[p].add(OPX);
				else	P[p].add(opl, opr, OPX);
			}
		}
	}
	return 0;
}
/*
4 5
4 4 4 4
count 1 4
add 1 4 3
count 1 4
add 2 3 40
count 1 4
*/