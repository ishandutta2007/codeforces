#include <iostream>
#include <map>
#include <string>
#include <utility>
using namespace std;
const int MAXN=211;
bool same(string A, string B){
	int al=A.length(), bl=B.length(), l=min(al, bl);
	if(al>bl)	return false;
	for(int i=1, a=al-1, b=bl-1;i<=l;++i, --a, --b){
		if(A[a]!=B[b])	return false;
	}
	return true;
}
struct Nums{
	int strcnt;
	bool in[MAXN];
	string n[MAXN];
	Nums(){
		strcnt=0;
		for(int i=0;i<MAXN;++i)	in[i]=true;
	}
	void c(){
		for(int i=1;i<=strcnt;++i){
			for(int j=1;j<=strcnt;++j){
				if(i==j)	continue;
				if(!in[j])	continue;
				if(same(n[i], n[j]))	in[i]=false;
			}
		}
	}
	void show(){
		int k=0;
		for(int i=1;i<=strcnt;++i)	if(in[i])	++k;
		cout << k << " ";
		for(int i=1;i<=strcnt;++i){
			if(in[i]){
				cout << n[i] << " ";
			}
		}
	}
} P[22];
int Pcnt=0;
map<string, int> T;
int N;
string name, input;
int cnt, at;
int main(){
	ios_base::sync_with_stdio(false);
	cin >> N;
	while(N--){
		cin >> name >> cnt;
		if(T[name])	at=T[name];
		else{
			T[name]=++Pcnt;
			at=T[name];
		}
		for(int i=1;i<=cnt;++i){
			cin >> input;
			P[at].n[++P[at].strcnt]=input;
		}
	}
	for(int i=1;i<=Pcnt;++i){
		P[i].c();
	}
	map<string, int>::iterator iT;
	int NN=0;
	for(iT=T.begin();iT!=T.end();++iT)	++NN;
	cout << NN << endl;
	pair<string, int> iTem;
	for(iT=T.begin();iT!=T.end();++iT){
		iTem=*iT;
		cout << iTem.first << " ";
		P[iTem.second].show();
		cout << endl;
	}
	return 0;
}