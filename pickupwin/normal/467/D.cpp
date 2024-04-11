#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
map<string, int> Table;
map<string, int>::const_iterator iF;
string input;
int M, N, Wcnt=0, Ecnt=0;
int Num[111111], FE[333333], Rcnt[333333], L[333333], Rank[333333];
bool Vis[333333];
struct Edge{
	int x, y, next;
} E[333333];
void addE(int a, int b){
	++Ecnt;
	E[Ecnt].x=a;
	E[Ecnt].y=b;
	E[Ecnt].next=FE[a];
	FE[a]=Ecnt;
}
void low(string& A){
	int l=A.length();
	for(int i=0;i<l;++i){
		if('A'<=A[i] && A[i]<='Z'){
			A[i]=A[i]-'A'+'a';
		}
	}
}
int cntR(string A){
	int l=A.length(), ret=0;
	for(int i=0;i<l;++i)
		if(A[i]=='r')	++ret;
	return ret;
}
bool lower(int at, int rr, int ll){
	if(Rcnt[at]==rr)	return L[at]<ll;
	return Rcnt[at]<rr;
}
bool upper(int at, int rr, int ll){
	if(Rcnt[at]==rr)	return L[at]>ll;
	return Rcnt[at]>rr;
}
void Qsort(int l, int r){
	int i=l, j=r, testR=Rcnt[Rank[(l+r)/2]], testL=L[Rank[(l+r)/2]], temp;
	while(i<=j){
		while(lower(Rank[i], testR, testL))	++i;
		while(upper(Rank[j], testR, testL))	--j;
		if(i<=j){
			temp=Rank[i];Rank[i]=Rank[j];Rank[j]=temp;
			++i;--j;
		}
	}
	if(i<r)	Qsort(i, r);
	if(l<j)	Qsort(l, j);
}
void DFS(int at, int rr, int ll){
	Rcnt[at]=rr;L[at]=ll;Vis[at]=true;
	for(int k=FE[at], to;k>0;k=E[k].next){
		to=E[k].y;
		if(Vis[to])	continue;
		DFS(to, rr, ll);
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	for(register int i=0;i<333333;++i){
		FE[i]=-1;
		Vis[i]=false;
		Rank[i]=i;
	}
	cin >> M;
	for(int i=1;i<=M;++i){
		cin >> input;
		low(input);
		iF=Table.find(input);
		if(iF!=Table.end())	Num[i]=iF->second;
		else{
			++Wcnt;
			Table.insert(make_pair(input, Wcnt));
			Rcnt[Wcnt]=cntR(input);
			L[Wcnt]=input.length();
			Num[i]=Wcnt;
		}
	}
	cin >> N;
	for(int i=1, a, b;i<=N;++i){
		cin >> input;
		low(input);
		iF=Table.find(input);
		if(iF!=Table.end())	a=iF->second;
		else{
			++Wcnt;
			Table.insert(make_pair(input, Wcnt));
			a=Wcnt;
			Rcnt[Wcnt]=cntR(input);
			L[Wcnt]=input.length();
		}
		cin >> input;
		low(input);
		iF=Table.find(input);
		if(iF!=Table.end())	b=iF->second;
		else{
			++Wcnt;
			Table.insert(make_pair(input, Wcnt));
			b=Wcnt;
			Rcnt[Wcnt]=cntR(input);
			L[Wcnt]=input.length();
		}
		addE(b, a);
	}
	/*
	for(int i=1;i<=N;++i)
		cout << E[i].x << " " << E[i].y << endl;
	*/
	Qsort(1, Wcnt);
	for(int i=1;i<=Wcnt;++i){
		if(!Vis[Rank[i]]){
			DFS(Rank[i], Rcnt[Rank[i]], L[Rank[i]]);
		}
	}
	long long ANSR=0LL, ANSL=0LL;
	for(int i=1;i<=M;++i){
		ANSR+=(long long)(Rcnt[Num[i]]);
		ANSL+=(long long)(L[Num[i]]);
	}
	cout << ANSR << " " << ANSL << endl;
	return 0;
}